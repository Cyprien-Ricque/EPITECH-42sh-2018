/*
** EPITECH PROJECT, 2018
** find_env_value.c
** File description:
** find env value
*/

#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include "my_42sh.h"
#include "my.h"

list_t *find_shell_node(exec_t *exe, char *name)
{
    list_t *tmp = exe->shell;

    for (; tmp != NULL; tmp = tmp->next) {
        if (tmp->names != NULL && strcmp(tmp->names, name) == SUCCESS)
            return (tmp);
    }
    return (NULL);
}

list_t *find_env_node(exec_t *exe, char *name)
{
    list_t *tmp = exe->env;

    for (; tmp != NULL; tmp = tmp->next) {
        if (tmp->names != NULL && strcmp(tmp->names, name) == SUCCESS)
            return (tmp);
    }
    return (NULL);
}

char *find_env_value(exec_t *exe, char *name)
{
    list_t *tmp = exe->env;
    char *empty = malloc(sizeof(char) * 1);

    if (!empty || !name)
        return (NULL);
    empty[0] = EMPTY;
    for (; tmp != NULL; tmp = tmp->next) {
        if (tmp->names != NULL && strcmp(tmp->names, name) == SUCCESS)
            return ((tmp->value == NULL) ? empty : tmp->value);
    }
    empty[0] = NO_REF;
    return (empty);
}

char *find_shell_value(exec_t *exe, char *name)
{
    list_t *tmp = exe->shell;
    char *empty = malloc(sizeof(char) * 1);

    if (!empty)
        return (NULL);
    empty[0] = EMPTY;
    for (; tmp != NULL; tmp = tmp->next) {
        if (tmp->names != NULL && strcmp(tmp->names, name) == SUCCESS)
            return ((tmp->value == NULL) ? empty : tmp->value);
    }
    empty[0] = NO_REF;
    return (empty);
}