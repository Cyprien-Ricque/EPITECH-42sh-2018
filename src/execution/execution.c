/*
** EPITECH PROJECT, 2018
** minishell_2
** File description:
** exec
*/

#include "execution.h"
#include "my.h"
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>

char cpy_env(exec_t *exe)
{
    char *value;

    for (list_t *tmp = exe->env; tmp; tmp = tmp->next) {
        if (!tmp->value || !tmp->names)
            continue;
        value = malloc(
            sizeof(char) * (m_slen(tmp->names) + 2 + m_slen(tmp->value)));
        if (!value)
            return (FAILURE);
        sprintf(value, "%s=%s", tmp->names, tmp->value);
        exe->tmp_env = m_arraycat(exe->tmp_env, value,
            m_arraylen((const char **)exe->tmp_env), SECOND);
        if (!exe->tmp_env)
            return (FAILURE);
    }
    return (SUCCESS);
}

char init_execution(exec_t *exe)
{
    char *value = get_value("PATH", exe->env);

    exe->paths = m_sarray(value, ':', false);
    exe->pid = malloc(sizeof(int));
    exe->r_values = malloc(2);
    if (!exe->pid || !exe->r_values)
        return (FAILURE);
    exe->pid[0] = -1;
    exe->r_values[0] = 0;
    if (exe->tmp_env && exe->tmp_env[0])
        free_array(exe->tmp_env);
    exe->tmp_env = malloc(sizeof(char **));
    if (!exe->tmp_env)
        return (FAILURE);
    exe->tmp_env[0] = NULL;
    if (cpy_env(exe) == FAILURE)
        return (FAILURE);
    return (SUCCESS);
}

char end_execution(exec_t *execn)
{
    free(execn->pid);
    free(execn->r_values);
    if (execn->paths)
        free_array(execn->paths);
    return (SUCCESS);
}

char execution(cmd_t *cmds, exec_t *exe)
{
    exe->to_exit = false;
    exe->actual_exit = false;
    exe->exit = 0;
    if (init_execution(exe) == FAILURE)
        return (FAILURE);
    if (m_pipe(cmds, exe) == FAILURE)
        return (FAILURE);
    if (exe->to_exit == true)
        close(0);
    return (SUCCESS);
}