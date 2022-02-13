/*
** EPITECH PROJECT, 2023
** PSU_42sh_2018
** File description:
** Created by charles,
*/

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include <builtins.h>
#include "parsing.h"
#include "execution.h"
#include "my.h"

int namelen(char *word, int pos)
{
    int n = 0;

    pos++;
    while (isalnum(word[pos]) != 0 || isalpha(word[pos]) != 0) {
        pos++;
        n++;
    }
    return n;
}

char *names(char *word, int *pos)
{
    int n = namelen(word, *pos);
    char *name = malloc(sizeof(char) * (n + 1));

    if (!name)
        return NULL;
    for (int i = 0; i <= n; name[i] = 0, i++);
    if (word[(*pos) + 1] == '?') {
        name[0] = '?';
        return name;
    }
    for (int i = 0; i <= *pos; word++, i++);
    for (int i = 0; i < n &&
        (isalnum(word[0]) != 0 || isalpha(word[0]) != 0); word++, i++) {
        name[i] = word[0];
    }
    name[n] = '\0';
    return name;
}

int getvalue(exec_t *exec, char **name, char *tmp, char *value)
{
    if (!value)
        return EXIT;
    if (value[0] != NO_REF) {
        *name = m_scat(*name, value, strlen(*name), 0);
        return SUCCESS;
    }
    value = find_shell_value(exec, tmp);
    if (!value)
        return EXIT;
    else if (value[0] == NO_REF && tmp[0] != 0) {
        fprintf(stderr, "%s: Undefined variable.\n", tmp);
        return FAILURE;
    }
    *name = m_scat(*name, value, strlen(*name), 0);
    return SUCCESS;
}

int mget(char **word, cmd_t *command, exec_t *exec, char **name)
{
    char *tmp = NULL;
    char *value = NULL;
    int r_value = 0;

    for (int i = 0; (*word)[i] != '\0'; i++) {
        if ((*word)[i] == '$' &&
            !(i >= 1 && ((*word)[i - 1] == '\\' || (*word)[i - 1] == '$'))) {
            tmp = names(*word, &i);
            value = find_env_value(exec, tmp);
            r_value = getvalue(exec, name, tmp, value);
            if (r_value == FAILURE || r_value == EXIT) {
                var_error(command, exec);
                return r_value;
            }
        }
    }
    return (SUCCESS);
}

int get_variable_name(char **word, cmd_t *command, exec_t *exec)
{
    char *name = malloc(sizeof(char) * (strlen(*word) + 1));
    int r_value = 0;

    if (!name)
        return EXIT;
    for (int i = 0; i < (int)strlen(*word); name[i] = '\0', i++);
    r_value = mget(word, command, exec, &name);
    if (r_value == FAILURE || r_value == EXIT)
        return r_value;
    if (!name)
        return EXIT;
    if (name[0] != 0) {
        free(*word);
        (*word) = name;
    }
    return 0;
}