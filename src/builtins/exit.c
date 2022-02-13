/*
** EPITECH PROJECT, 2018
** exit.c
** File description:
** exit management
*/

#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <errno.h>
#include <ctype.h>
#include "builtins.h"
#include "execution.h"
#include "my.h"

char check_exit_arg(cmd_t *cmd, exec_t *exe)
{
    char *ptr;
    long exit_value = strtol(cmd->cmd[1], &ptr, 10);

    if (isdigit(cmd->cmd[1][0]) != 0 && isalpha(ptr[0]) != 0) {
        dprintf(2, "exit: Badly formed number.\n");
        return (cmd_error(cmd, exe));
    }
    if (ptr[0] != '\0') {
        dprintf(2, "exit: Expression Syntax.\n");
        return (cmd_error(cmd, exe));
    }
    if (cmd->redir.out != PIPE) {
        exe->exit = exit_value;
        exe->to_exit = true;
        exe->actual_exit = true;
    }
    close(0);
    return (SUCCESS);
}

char m_exit(cmd_t *cmd, exec_t *exe)
{
    if (m_arraylen((const char **)cmd->cmd) == 1) {
        exe->exit = 0;
        close(0);
        return (SUCCESS);
    }
    if (m_arraylen((const char **)cmd->cmd) == 2)
        return (check_exit_arg(cmd, exe));
    if (m_arraylen((const char **)cmd->cmd) > 2) {
        dprintf(2, "exit: Expression Syntax.\n");
        return (cmd_error(cmd, exe));
    }
    return (SUCCESS);
}