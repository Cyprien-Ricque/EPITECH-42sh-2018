/*
** EPITECH PROJECT, 2018
** minishell_2
** File description:
** pipe
*/

#include "execution.h"
#include "alias.h"
#include "my.h"
#include <unistd.h>
#include <stdio.h>

void replace(cmd_t *command, int *tmp, int save)
{
    if (command->redir.in == PIPE)
        close(save);
    if (command->redir.in == SIMPLE || command->redir.in == DOUBLE ||
        command->redir.in == PIPE)
        dup2(tmp[0], 0);
    if (command->redir.out == SIMPLE || command->redir.out == DOUBLE ||
        command->redir.out == PIPE)
        dup2(tmp[1], 1);
}