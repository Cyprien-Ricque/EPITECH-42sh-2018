/*
** EPITECH PROJECT, 2023
** PSU_42sh_2018
** File description:
** Created by charles,
*/

#include <stdio.h>
#include <string.h>
#include "my.h"
#include "parsing.h"
#include "execution.h"

int get_redir_tilde(cmd_t *command, char *home)
{
    if ((*command).redir.in_name && (*command).redir.in_name[0] == '~') {
        (*command).redir.in_name++;
        (*command).redir.in_name = m_scat(home, (*command).redir.in_name,
            strlen(home), 0);
        if (!(*command).redir.in_name)
            return EXIT;
    }
    if ((*command).redir.out_name && (*command).redir.out_name[0] == '~') {
        (*command).redir.out_name++;
        (*command).redir.out_name = m_scat(home, (*command).redir.out_name,
            strlen(home), 0);
        if (!(*command).redir.out_name)
            return EXIT;
    }
    return SUCCESS;
}

int is_tilde(cmd_t *command)
{
    for (int i = 0; (*command).cmd && (*command).cmd[i] != NULL; i++) {
        if ((*command).cmd[i][0] == '~')
            return SUCCESS;
    }
    if (((*command).redir.in_name && (*command).redir.in_name[0] == '~') ||
        ((*command).redir.out_name && (*command).redir.out_name[0] == '~'))
        return SUCCESS;
    return FAILURE;
}

int get_tilde(cmd_t *command, exec_t *exec)
{
    char *home = get_value("HOME", exec->env);

    if (!home) {
        if (is_tilde(command) == SUCCESS) {
            fprintf(stderr, "No $home variable set.\n");
            return FAILURE;
        }
        return SUCCESS;
    }
    for (int i = 0; (*command).cmd && (*command).cmd[i] != NULL; i++) {
        if ((*command).cmd[i][0] == '~') {
            (*command).cmd[i]++;
            (*command).cmd[i] = m_scat(home, (*command).cmd[i], strlen(home),
                0);
            if (!(*command).cmd[i])
                return EXIT;
        }
    }
    return get_redir_tilde(command, home);
}