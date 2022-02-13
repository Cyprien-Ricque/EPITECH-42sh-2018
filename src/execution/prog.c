/*
** EPITECH PROJECT, 2018
** minishell_2
** File description:
** prog
*/

#include <stdlib.h>
#include <fcntl.h>
#include <errno.h>
#include <stdio.h>
#include "execution.h"
#include "my.h"
#include <unistd.h>

char *local(char *command)
{
    if (access(command, F_OK | X_OK) != -1 &&
        is_file(command, false, false) == true)
        return (command);
    else if (access(command, F_OK) == -1) {
        return (NULL);
    } else {
        return (NULL);
    }
}

char *find(char *command, char **paths)
{
    char *tmp;

    if (is_local(command) == true)
        return (local(command));
    if (!paths || !paths[0])
        return (NULL);
    for (int i = 0; paths[i]; ++i) {
        tmp = malloc(sizeof(char) * (m_slen(paths[i]) + 2 + m_slen(command)));
        if (!tmp)
            return (NULL);
        sprintf(tmp, "%s/%s", paths[i], command);
        if (access(tmp, F_OK | X_OK) != -1)
            return (tmp);
        free(tmp);
    }
    return (NULL);
}

void free_son(exec_t *execn, cmd_t *command)
{
    free(execn->pid);
    free(command->cmd);
}

char exec(cmd_t *command, exec_t *execn)
{
    char status = 0;

    if (is_builtins(command->cmd[0]) == true && command->redir.out == PIPE)
        exit(builtins(command, execn));
    if (is_builtins(command->cmd[0]) == true && command->redir.out != PIPE)
        return (builtins(command, execn));
    command->bin = find(command->cmd[0], execn->paths);
    if (!command->bin)
        return (invalid_com(command->cmd[0]));
    status = (char)execve(command->bin, command->cmd, execn->tmp_env);
    if (errno == 8)
        fprintf(stderr, "%s: Exec format error. Wrong Architecture.\n",
        command->bin);
    exit(status);
}