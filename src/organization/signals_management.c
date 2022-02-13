/*
** EPITECH PROJECT, 2018
** minishell_2
** File description:
** main
*/

#include <wait.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include "execution.h"
#include "my.h"

void error_messages(bool *first, int ct, int *sts)
{
    for (ct = 0; sts[ct] != -1; ++ct);
    for (ct -= 1; ct >= 0; --ct)
        (*first) = exec_errors(sts[ct], (*first));
}

char get_wait_rv(exec_t *execn, int ct, int *status, int **sts)
{
    waitpid(execn->pid[ct], status, 0);
    (*status) = (*status) == 256 ? 1 : (*status);
    (*sts) = m_intcat((*sts), (*status));
    if (!(*sts) || (*status) == FAILURE)
        return (FAILURE);
    return (SUCCESS);
}

void get_rv_builtins(exec_t *execn, int ct, int *rv, int *status)
{
    (*status) = ct < m_slen(execn->r_values) ? execn->r_values[ct] : 0;
    (*rv) = (*rv) ?
        (*rv) : (*status) == 13 ? 141 : (*status) == -1 ? 0 : (*status);
}

long get_rv(exec_t *execn, bool *first)
{
    int ct = 0;
    int rv = 0;
    int status = 0;
    int *sts = malloc(8);

    if (!sts || !execn || !first)
        return (-1);
    sts[0] = -1;
    for (ct = 0; execn->pid[ct] != -1; ++ct);
    for (ct = ct - 1; ct >= 0; --ct) {
        if (execn->pid[ct] != -2) {
            if (get_wait_rv(execn, ct, &status, &sts) == FAILURE)
                return (-1);
            rv = rv ? rv : status == 13 ? 141 : status;
        } else
            get_rv_builtins(execn, ct, &rv, &status);
    }
    error_messages(first, ct, sts);
    return (execn->actual_exit == true ? execn->exit : (long)rv);
}

char signal_management(exec_t *execn, cmd_t UNUSED *commands)
{
    bool first = true;
    long rv = 0;
    list_t *tmp = find_var("?", execn->shell);

    if (!tmp || !execn->pid || !execn->r_values)
        return (FAILURE);
    rv = get_rv(execn, &first) % 255;
    tmp->value = m_sdup(m_retbase(rv, 10), 0);
    if (rv == -1 || !tmp->value)
        return (FAILURE);
    if (first == false)
        write(2, "\n", 1);
    if (tmp->link) {
        tmp->link->value = m_sdup(m_retbase(rv, 10), 0);
        if (!tmp->link->value)
            return (FAILURE);
    }
    execn->actual_exit = false;
    return (SUCCESS);
}