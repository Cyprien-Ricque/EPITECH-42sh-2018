/*
** EPITECH PROJECT, 2023
** PSU_42sh_2018
** File description:
** Created by charles,
*/

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "parsing.h"

int get_parenthesis(cmd_t **command, int count, char **line, int *i)
{
    if (line[*i][0] != ')')
        return 0;
    if ((*command)[count].cmd) {
        fprintf(stderr, "Badly placed ()'s.\n");
        return FAILURE;
    }
    (*command)[count].cmd = malloc(sizeof(char *) * 2);
    if (!(*command)[count].cmd)
        return EXIT;
    (*command)[count].cmd[0] = malloc(
        sizeof(char) * (strlen(line[(*i) + 1]) + 1));
    if (!(*command)[count].cmd[0])
        return EXIT;
    return SUCCESS;
}