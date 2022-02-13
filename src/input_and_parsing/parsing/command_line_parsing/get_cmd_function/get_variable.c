/*
** EPITECH PROJECT, 2023
** PSU_42sh_2018
** File description:
** Created by charles,
*/

#include <parsing.h>
#include <stdlib.h>
#include <string.h>
#include "my.h"

char **init_array(cmd_t command)
{
    int i = 0;
    char **array = malloc(
        sizeof(void *) * (m_arraylen((char const **)command.cmd) + 3));

    if (!array)
        return NULL;
    if (command.cmd) {
        for (; command.cmd != NULL; i++)
            array[i] = command.cmd[i];
    }
    if (command.redir.out_name) {
        array[i] = command.redir.out_name;
        i++;
    }
    if (command.redir.in_name) {
        array[i] = command.redir.in_name;
        i++;
    }
    array[i] = NULL;
    return array;
}

static int replace(char *str)
{
    if (!str)
        return false;
    for (int i = 0; str[i]; i++) {
        if (i == 0 && str[i] == '~')
            return true;
        if (str[i] == '$')
            return true;
    }
    return false;
}

int replace_variable(cmd_t *command, exec_t *exec)
{
    int rv = 0;

    for (int j = 0; (*command).cmd[j] && (*command).cmd[j] != NULL; j++) {
        if (replace((*command).cmd[j]) == false)
            continue;
        rv = get_variable_name(&(*command).cmd[j], command, exec);
        if (rv == FAILURE || rv == EXIT)
            return rv;
    }
    if (replace((*command).redir.in_name) == true)
        rv = get_variable_name(&(*command).redir.in_name, command, exec);
    if (rv == FAILURE || rv == EXIT)
        return rv;
    if (replace((*command).redir.out_name) == true)
        rv = get_variable_name(&(*command).redir.out_name, command, exec);
    if (rv == FAILURE || rv == EXIT)
        return rv;
    return get_tilde(command, exec);
}