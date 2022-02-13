/*
** EPITECH PROJECT, 2023
** PSU_42sh_2018
** File description:
** Created by charles,
*/

#include "parsing.h"
#include <stdio.h>
#include <string.h>

int get_or(cmd_t **command, int count, char **line, int *i)
{
    if (strcmp(line[*i], "||") != 0)
        return 0;
    if (!line[(*i) + 1] || is_separators(line[(*i) + 1], 0) == true) {
        fprintf(stderr, "Invalid null command.\n");
        return FAILURE;
    }
    (*command)[count].operator.out = OR;
    (*command)[count + 1].operator.in = OR;
    return SUCCESS;
}

int get_and(cmd_t **command, int count, char **line, int *i)
{
    if (strcmp(line[*i], "&&") != 0)
        return 0;
    if (!line[(*i) + 1] || is_separators(line[(*i) + 1], 0) == true) {
        fprintf(stderr, "&&Invalid null command.\n");
        return FAILURE;
    }
    (*command)[count].operator.out = AND;
    (*command)[count + 1].operator.in = AND;
    return SUCCESS;
}

int get_semicolons(UNUSED cmd_t **command, UNUSED int count, char **line,
    int *i)
{
    if (strcmp(line[*i], ";") != 0)
        return 0;
    if (line[(*i) + 1] != NULL && is_separators(line[(*i) + 1], 0) == true) {
        fprintf(stderr, "Invalid null command.\n");
        return FAILURE;
    }
    return SUCCESS;
}