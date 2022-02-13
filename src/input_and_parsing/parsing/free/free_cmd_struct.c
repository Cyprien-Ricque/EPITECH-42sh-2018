/*
** EPITECH PROJECT, 2019
** PSU_42sh_2018
** File description:
** Created by charles,
*/

#include "parsing.h"
#include "stdlib.h"

void free_pointers(cmd_t command)
{
    void *pointer[4] = {command.bin, command.sub_cmd, command.redir.in_name,
        command.redir.out_name};
    for (int j = 0; j != 4; j++)
        if (pointer[j])
            free(pointer[j]);
}

void *free_cmd_struct(cmd_t *command)
{
    for (int i = 0; command[i].valid != false; i++) {
        free_pointers(command[i]);
        if (command[i].cmd)
            free_array(command[i].cmd);
    }
    free(command);
    return NULL;
}