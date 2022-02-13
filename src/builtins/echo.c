/*
** EPITECH PROJECT, 2019
** echo_management
** File description:
** echo management for
*/

#include <stdlib.h>
#include <stdio.h>
#include <memory.h>
#include "builtins.h"
#include "my_42sh.h"
#include "my.h"

void m_echo_content(const cmd_t *cmd, int i)
{
    for (; cmd->cmd[i] != NULL; i++) {
        if (cmd->cmd[i + 1] != NULL)
            m_printf(1, "%s ", cmd->cmd[i]);
        else
            m_printf(1, "%s", cmd->cmd[i]);
    }
}

char m_echo(cmd_t *cmd, exec_t *exec UNUSED)
{
    int i = 1;

    if (!cmd->cmd[1]) {
        m_printf(1, "\n");
        return (SUCCESS);
    }
    if (strcmp(cmd->cmd[1], "-n") == 0)
        i = 2;
    if (cmd->cmd[i] != NULL)
        m_echo_content(cmd, i);
    if (strcmp(cmd->cmd[1], "-n") != 0)
        m_printf(1, "\n");
    return (SUCCESS);
}