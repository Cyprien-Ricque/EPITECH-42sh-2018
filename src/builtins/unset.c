/*
** EPITECH PROJECT, 2018
** unset.c
** File description:
** unset builtin
*/

#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include <ctype.h>
#include <unistd.h>
#include "execution.h"
#include "my_42sh.h"
#include "my.h"
#include "builtins.h"

char delete_shell_node(exec_t *exec, list_t *prev, int i)
{
    if (i == 0)
        exec->shell = prev->next;
    else if (prev->next->next != NULL)
        prev->next = prev->next->next;
    else
        prev->next = NULL;
    return (SUCCESS);
}

char m_unset(cmd_t *cmd, exec_t *exe)
{
    list_t *tmp = exe->shell;

    if (m_arraylen((const char **)cmd->cmd) == 1) {
        dprintf(2, "unset: Too few arguments.\n");
        return (cmd_error(cmd, exe));
    }
    for (int y = 1; cmd->cmd[y] != NULL; y++) {
        for (int i = 0; tmp != NULL; i++, tmp = tmp->next) {
            if (i == 0 && tmp->names != NULL && strcmp(tmp->names,
                cmd->cmd[y]) == SUCCESS)
                delete_shell_node(exe, tmp, i);
            if (tmp->next != NULL && tmp->next->names != NULL && strcmp
            (tmp->next->names, cmd->cmd[y]) == SUCCESS)
                delete_shell_node(exe, tmp, i + 1);
        }
    }
    return (SUCCESS);
}