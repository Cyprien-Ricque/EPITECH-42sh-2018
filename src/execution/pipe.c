/*
** EPITECH PROJECT, 2018
** minishell_2
** File description:
** pipe
*/

#include "execution.h"
#include "parsing.h"
#include "alias.h"
#include "my.h"
#include <unistd.h>
#include <stdio.h>

void next(int *pipe_fd, cmd_t *command, int save, exec_t *execn)
{
    if (command->redir.in == PIPE)
        dup2(save, 0);
    dup2(pipe_fd[1], 1);
    if (is_builtins(command->cmd[0]) == true ||
        find(command->cmd[0], execn->paths))
        close(pipe_fd[0]);
}

int new_proc(cmd_t *command, exec_t *execn, int save)
{
    int pipe_fd[2];
    pid_t pid = 1;
    int tmp[2] = {dup(0), dup(1)};
    int dup = dup_entries(command);

    pipe(pipe_fd);
    if (dup != -1 && (is_builtins(command->cmd[0]) == true ||
        find(command->cmd[0], execn->paths)))
        pid = fork();
    if (dup != -1 && (pid == 0 || (!find(command->cmd[0], execn->paths) &&
        is_builtins(command->cmd[0]) == false))) {
        next(pipe_fd, command, save, execn);
        if (exec(command, execn) == FAILURE)
            return (FAILURE);
    }
    replace(command, tmp, save);
    rv_management(command, execn, pid, dup);
    close(pipe_fd[1]);
    return (pipe_fd[0]);
}

void last_proc(cmd_t *command, exec_t *execn, int save)
{
    int tmp[2] = {dup(0), dup(1)};
    pid_t pid = getpid();
    int dup = dup_entries(command);

    if (dup != -1 && is_builtins(command->cmd[0]) == false &&
        find(command->cmd[0], execn->paths))
        pid = fork();
    if ((is_builtins(command->cmd[0]) == true || pid == 0 ||
        !find(command->cmd[0], execn->paths)) && dup != -1) {
        if (command->redir.in == PIPE)
            dup2(save, 0);
        if (exec(command, execn) == FAILURE)
            return;
    }
    replace(command, tmp, save);
    rv_management(command, execn, pid, dup);
}

int last_com_management(cmd_t *commands, exec_t *execn, int save, int *i)
{
    if (next_com(commands, execn, i) == true)
        last_proc(&commands[(*i)], execn, save);
    if (signal_management(execn, commands) == FAILURE ||
        end_execution(execn) == FAILURE || init_execution(execn) == FAILURE)
        return (FAILURE);
    return (SUCCESS);
}

char m_pipe(cmd_t *commands, exec_t *execn)
{
    int save = 0;
    int rv = 0;

    for (int i = 0; commands && commands[i].valid && commands[i].cmd[0]; ++i) {
        rv = replace_variable(&commands[i], execn);
        if (rv == EXIT)
            return (FAILURE);
        if (rv == FAILURE)
            continue;
        if (commands[i].redir.out == PIPE && commands[i].cmd[0][0]) {
            if (next_com(commands, execn, &i) == false)
                continue;
            save = new_proc(&commands[i], execn, save);
        } else if (commands[i].cmd[0] && commands[i].cmd[0][0])
            if (last_com_management(commands, execn, save, &i) == FAILURE)
                return (FAILURE);
    }
    return (SUCCESS);
}