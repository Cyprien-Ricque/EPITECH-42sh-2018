/*
** EPITECH PROJECT, 2018
** 42sh
** File description:
** env
*/

#include <stdlib.h>
#include <stdio.h>
#include "my_42sh.h"
#include "my.h"
#include "execution.h"
#include "builtins.h"

char arg_number_is_ok(exec_t *exe, cmd_t *cmd, int min, int max)
{
    int ct = 0;

    while (cmd->cmd[ct])
        ++ct;
    if (ct >= min && ct <= max)
        return (SUCCESS);
    m_puts(cmd->cmd[0], 2);
    m_puts(": Too many arguments.\n", 2);
    return (cmd_error(cmd, exe));
}

char var_is_ok(const char *var, bool print)
{
    if (!((var[0] >= 'a' && var[0] <= 'z') ||
    (var[0] >= 'A' && var[0] <= 'Z') || var[0] == '_')) {
        if (print == true)
            dprintf(2, "setenv: Variable name must begin with a letter.\n");
        return (ERROR);
    }
    for (int i = 0; var[i]; ++i)
        if (!((var[i] >= 'a' && var[i] <= 'z') ||
        (var[i] >= 'A' && var[i] <= 'Z') ||
        (var[i] >= '0' && var[i] <= '9') || var[i] == '_')) {
            if (print == true)
                dprintf(2, "setenv: Variable name "
                "must contain alphanumeric characters.\n");
            return (ERROR);
        }
    return (SUCCESS);
}

char m_env(cmd_t *cmd, exec_t *exe)
{
    list_t *tmp = exe->env;

    if (cmd->cmd[1]) {
        dprintf(2, "env: ‘%s’: No such file or directory\n", cmd->cmd[1]);
        return (cmd_error(cmd, exe));
    }
    while (tmp != NULL) {
        if (tmp->names != NULL)
            m_printf(1, "%s=", tmp->names);
        if (tmp->value != NULL)
            m_printf(1, "%s\n", tmp->value);
        if (tmp->value == NULL && tmp->names != NULL)
            m_printf(1, "\n");
        tmp = tmp->next;
    }
    return (SUCCESS);
}