/*
** EPITECH PROJECT, 2018
** minishell_2
** File description:
** pipe
*/

#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include "execution.h"
#include "my.h"
#include "builtins.h"
#include "alias.h"

char const *builtin[NB_BUILTINS] = {"env", "setenv", "unsetenv", "cd", "exit",
    "echo", "set", "unset", "where", "which", "alias", "history", "builtins",
    NULL};

char (*builtins_func[NB_BUILTINS])(cmd_t *command, exec_t *execn) =
{
    m_env, m_setenv, m_unsetenv, m_cd, m_exit, m_echo, m_set, m_unset,
    m_where, m_which, m_alias, m_history, m_builtins,  NULL
};

char m_builtins(cmd_t *cmd UNUSED, exec_t *exe UNUSED)
{
    for (int i = 0; builtin[i] != NULL; i++)
        m_printf(1, "%s\n", (char *)builtin[i]);
    return (SUCCESS);
}

bool is_builtins(char *command)
{
    for (int i = 0; builtin[i]; ++i)
        if (!m_scmp(builtin[i], command, 0))
            return (true);
    return (false);
}

char builtins(cmd_t *command, exec_t *execn)
{
    int i;

    for (i = 0; builtin[i]; ++i)
        if (!m_scmp(builtin[i], command->cmd[0], 0))
            if (builtins_func[i](command, execn) == FAILURE)
                return (FAILURE);
    return (SUCCESS);
}