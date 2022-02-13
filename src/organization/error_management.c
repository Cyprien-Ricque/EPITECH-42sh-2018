/*
** EPITECH PROJECT, 2018
** 42sh
** File description:
** 42sh
*/

#include <stdbool.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <wait.h>
#include "execution.h"
#include "my.h"

char cmd_error(cmd_t *command, exec_t UNUSED *execn)
{
    int unassigned = -2;
    char error = 1;

    if (command->redir.out == PIPE)
        exit(1);
    execn->r_values = m_scat(execn->r_values, &error, m_slen(execn->r_values),
        1);
    execn->pid = m_intcat(execn->pid, unassigned);
    if (!execn->r_values || !execn->pid)
        return (FAILURE);
    return (SUCCESS);
}

char var_error(UNUSED cmd_t *command, exec_t UNUSED *execn)
{
    int unassigned = -2;
    char error = 1;

    execn->r_values = m_scat(execn->r_values, &error, m_slen(execn->r_values),
        1);
    execn->pid = m_intcat(execn->pid, unassigned);
    if (!execn->r_values || !execn->pid)
        return (FAILURE);
    return (SUCCESS);
}

bool exec_errors(int status, bool first)
{
    if (WIFSIGNALED(status) && WTERMSIG(status) == SIGFPE && first == true)
        m_puts("Floating exception", 2);
    if (WIFSIGNALED(status) && WTERMSIG(status) == SIGSEGV && first == true)
        m_puts("Segmentation fault", 2);
    if (WIFSIGNALED(status) && WTERMSIG(status) == SIGBUS && first == true)
        m_puts("Bus error", 2);
    if (WIFSIGNALED(status) && WTERMSIG(status) == SIGSTKFLT && first == true)
        m_puts("Stack fault", 2);
    if (WIFSIGNALED(status) && WTERMSIG(status) == SIGABRT && first == true)
        m_puts("Abort", 2);
    if (WIFSIGNALED(status) && WCOREDUMP(status) && first == true)
        m_puts(" (core dumped)", 2);
    else if (WIFSIGNALED(status) && WCOREDUMP(status) && first == false)
        m_puts("  (core dumped)", 2);
    if ((WIFSIGNALED(status) && WCOREDUMP(status)) || first == false)
        return (false);
    return (true);
}

void rv_management_2(const cmd_t *command, exec_t *execn, pid_t pid, int dup)
{
    char unassigned = -2;
    char error = 1;

    if (dup != -1 && is_builtins(command->cmd[0]) == true &&
        command->redir.out == PIPE) {
        execn->pid = m_intcat(execn->pid, pid);
        execn->r_values = m_scat(execn->r_values, &unassigned,
            m_slen(execn->r_values), 1);
    }
    if ((is_builtins(command->cmd[0]) == false &&
        !find(command->cmd[0], execn->paths)) || dup == -1) {
        execn->pid = m_intcat(execn->pid, (int)unassigned);
        execn->r_values = m_scat(execn->r_values, &error,
            m_slen(execn->r_values), 1);
    }
}

void rv_management(cmd_t *command, exec_t *execn, pid_t pid, int dup)
{
    char unassigned = -2;

    if (dup != -1 && is_builtins(command->cmd[0]) == false &&
        find(command->cmd[0], execn->paths)) {
        execn->pid = m_intcat(execn->pid, pid);
        execn->r_values = m_scat(execn->r_values, &unassigned,
            m_slen(execn->r_values), 1);
        return;
    }
    rv_management_2(command, execn, pid, dup);
}