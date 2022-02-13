/*
** EPITECH PROJECT, 2019
** PSU_42sh_2018
** File description:
** Created by charles,
*/

#include "parsing.h"
#include <stdlib.h>

red_t init_redirection_struct(void)
{
    red_t redirection;

    redirection.in = false;
    redirection.in_name = NULL;
    redirection.out = false;
    redirection.out_name = NULL;
    return redirection;
}

op_t init_operators_struct(void)
{
    op_t operator;

    operator.out = false;
    operator.in = false;
    operator.in_r_value = 0;
    operator.out_r_value = 0;
    return operator;
}

cmd_t *init_cmd_struct(int nb_cmd)
{
    cmd_t *command = malloc(sizeof(cmd_t) * (nb_cmd + 1));

    if (!command)
        return NULL;
    for (int i = 0; i < nb_cmd; i++) {
        command[i].valid = true;
        command[i].bin = NULL;
        command[i].cmd = NULL;
        command[i].sub_cmd = NULL;
        command[i].redir = init_redirection_struct();
        command[i].operator = init_operators_struct();
    }
    command[nb_cmd].valid = false;
    return command;
}