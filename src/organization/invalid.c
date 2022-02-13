/*
** EPITECH PROJECT, 2018
** minishell_2
** File description:
** main
*/

#include <stdbool.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <wait.h>
#include "execution.h"
#include "my.h"

bool is_local(char *command)
{
    for (int i = 0; command[i]; ++i)
        if ((command[i] == '.' && i == 0) || command[i] == '/')
            return (true);
    return (false);
}

char invalid_com(char *command)
{
    if (access(command, F_OK) != -1 && (is_local(command) == true))
        fprintf(stderr, "%s: Permission denied.\n", command);
    else
        fprintf(stderr, "%s: Command not found.\n", command);
    return (SUCCESS);
}