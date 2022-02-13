/*
** EPITECH PROJECT, 2018
** set.c
** File description:
** set builtin
*/

#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include <ctype.h>
#include "my_42sh.h"
#include "my.h"
#include "execution.h"
#include "builtins.h"

char add_shell_node(list_t *exe, char *arg)
{
    int c;
    list_t *new_node = malloc(sizeof(list_t));

    if (new_node == NULL)
        return (FAILURE);
    for (c = 0; arg[c] != '=' && arg[c] != '\0'; c++);
    new_node->names = strndup(arg, (size_t)c);
    if (!new_node->names)
        return (FAILURE);
    if (arg[c] == '\0' || arg[c + 1] == '\0')
        new_node->value = NULL;
    else {
        new_node->value = strdup(&arg[c + 1]);
        if (!new_node->value)
            return (FAILURE);
    }
    set_node_ptr(exe, new_node);
    return (SUCCESS);
}

char change_shell_value(list_t *node, char *arg, bool *chg)
{
    int c;
    char *value;

    (*chg) = true;
    for (c = 0; arg[c] != '=' && arg[c] != '\0'; c++);
    if (arg[c] == '\0' || arg[c + 1] == '\0') {
        node->value = NULL;
        return (SUCCESS);
    }
    value = strdup(&arg[c + 1]);
    if (value != NULL) {
        node->value = strdup(value);
        if (!node->value)
            return (FAILURE);
        if (node->link != NULL)
            node->link->value = strdup(value);
        return (SUCCESS);
    }
    node->value = NULL;
    return (SUCCESS);
}

char set_new_shell_var(cmd_t *cmd, exec_t *exe)
{
    list_t *tmp;
    char *name;
    bool chg;

    for (int y = 1; cmd->cmd[y] != NULL; y++) {
        if (set_error_management(cmd, exe, cmd->cmd[y], &chg) == ERROR)
            return (cmd_error(cmd, exe));
        name = get_shell_var_name(cmd->cmd[y]);
        if (!name)
            return (FAILURE);
        for (tmp = exe->shell; tmp->next != NULL; tmp = tmp->next)
            if (tmp->names != NULL && strcmp(tmp->names, name) == 0)
                change_shell_value(tmp, cmd->cmd[y], &chg);
        if (tmp->names != NULL && strcmp(tmp->names, name) == 0)
            change_shell_value(tmp, cmd->cmd[y], &chg);
        else if (chg != true && add_shell_node(tmp, cmd->cmd[y]) == FAILURE)
            return (FAILURE);
    }
    return (SUCCESS);
}

char m_set(cmd_t *cmd, exec_t *exe)
{
    if (m_arraylen((const char **)cmd->cmd) == 1)
        m_print_set(cmd, exe);
    else {
        if (set_new_shell_var(cmd, exe) == FAILURE)
            return (FAILURE);
    }
    return (SUCCESS);
}