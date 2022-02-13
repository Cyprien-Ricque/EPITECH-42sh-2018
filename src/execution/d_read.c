/*
** EPITECH PROJECT, 2018
** minishell_2
** File description:
** double_read
*/

#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>
#include "execution.h"
#include "my.h"

char *take_entrie(char *end)
{
    char *buf = gnl(0);
    char *str = malloc(sizeof(char));

    if (!str)
        return (NULL);
    str[0] = 0;
    while (buf && m_scmp(buf, end, 0)) {
        str = m_scat(str, buf, m_slen(str), 0);
        str = m_scat(str, "\n", m_slen(str), 1);
        free(buf);
        buf = gnl(0);
    }
    free(buf);
    return (str);
}

int double_read(cmd_t *command)
{
    int pipe_fd[2];
    pid_t pid;

    pipe(pipe_fd);
    char *buf = take_entrie(command->redir.in_name);
    if (!buf)
        return (FAILURE);
    pid = fork();
    if (pid == 0) {
        close(pipe_fd[0]);
        dup2(pipe_fd[1], 1);
        write(1, buf, (size_t)m_slen(buf));
        close(pipe_fd[1]);
        exit(0);
    }
    free(buf);
    close(pipe_fd[1]);
    dup2(pipe_fd[0], 0);
    close(pipe_fd[0]);
    return (SUCCESS);
}