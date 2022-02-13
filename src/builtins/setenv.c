/*
** EPITECH PROJECT, 2018
** setenv.c
** File description:
** setenv
*/

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "execution.h"
#include "my.h"
#include "builtins.h"

int change_value(list_t *node, char *value)
{
    if (value != NULL) {
        node->value = strdup(value);
        if (!node->value)
            return (FAILURE);
        if (node->link != NULL) {
            node->link->value = strdup(value);
            return ((node->link->value) == NULL ? FAILURE : SUCCESS);
        }
        return (SUCCESS);
    }
    node->value = NULL;
    return (SUCCESS);
}

char new_env_line(list_t *tmp, cmd_t *cmd)
{
    char *str;

    if (cmd->cmd[2] != NULL)
        str = malloc(sizeof(char) * (strlen(cmd->cmd[1]) +
            strlen(cmd->cmd[2]) + 2));
    else
        str = malloc(sizeof(char) * (strlen(cmd->cmd[1]) + 2));
    if (!str)
        return (FAILURE);
    strcpy(str, cmd->cmd[1]);
    str[strlen(cmd->cmd[1])] = '=';
    if (cmd->cmd[2] != NULL)
        strcpy(&str[strlen(cmd->cmd[1]) + 1], cmd->cmd[2]);
    else
        str[strlen(cmd->cmd[1]) + 1] = '\0';
    if (append_env_node(tmp, str) == FAILURE)
        return (FAILURE);
    return (SUCCESS);
}

char m_setenv(cmd_t *cmd, exec_t *exe)
{
    list_t *tmp = exe->env;

    if (m_arraylen((const char **)cmd->cmd) == 1)
        return (m_env(cmd, exe));
    if (var_is_ok(cmd->cmd[1], true) == ERROR)
        return (cmd_error(cmd, exe));
    if (arg_number_is_ok(exe, cmd, 0, 3) == ERROR)
        return (cmd_error(cmd, exe));
    for (; tmp->next != NULL; tmp = tmp->next) {
        if (tmp->names != NULL && strcmp(tmp->names, cmd->cmd[1]) == 0)
            return (change_value(tmp, cmd->cmd[2]));
    }
    if (tmp->names != NULL && strcmp(tmp->names, cmd->cmd[1]) == 0)
        return (change_value(tmp, cmd->cmd[2]));
    if (new_env_line(tmp, cmd) == FAILURE)
        return (FAILURE);
    return (SUCCESS);
}