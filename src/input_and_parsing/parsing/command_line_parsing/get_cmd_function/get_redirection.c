/*
** EPITECH PROJECT, 2023
** PSU_42sh_2018
** File description:
** Created by charles,
*/

#include "parsing.h"
#include <string.h>
#include <stdio.h>

int get_in_redirection(cmd_t **command, UNUSED int count, char **line, int *i)
{
    if (strcmp("<", line[*i]) != 0 && strcmp("<<", line[*i]) != 0)
        return 0;
    if ((*command)[count].redir.in == 0)
        (*command)[count].redir.in = (strlen(line[*i]) == 1) ? SIMPLE : DOUBLE;
    else {
        fprintf(stderr, "Ambiguous input redirect.\n");
        return FAILURE;
    }
    if (line[(*i) + 1] != NULL && is_special_char(line[(*i) + 1], 1) == false) {
        (*command)[count].redir.in_name = strdup(line[(*i) + 1]);
        if (!(*command)[count].redir.in_name)
            return EXIT;
    } else {
        fprintf(stderr, "Missing name for redirect.\n");
        return FAILURE;
    }
    (*i)++;
    return SUCCESS;
}

int get_out_redirection(cmd_t **command, int count, char **line, int *i)
{
    if (strcmp(">", line[*i]) != 0 && strcmp(">>", line[*i]) != 0)
        return 0;
    if ((*command)[count].redir.out == 0)
        (*command)[count].redir.out = (strlen(line[*i]) == 1) ? SIMPLE : DOUBLE;
    else {
        fprintf(stderr, "Ambiguous output redirect.\n");
        return FAILURE;
    }
    if (line[(*i) + 1] != NULL && is_special_char(line[(*i) + 1], 1) == false) {
        (*command)[count].redir.out_name = strdup(line[(*i) + 1]);
        if (!(*command)[count].redir.out_name)
            return EXIT;
    } else {
        fprintf(stderr, "Missing name for redirect.\n");
        return FAILURE;
    }
    (*i)++;
    return SUCCESS;
}

int get_pipe(cmd_t **command, int count, char **line, int *i)
{
    if (strcmp(line[*i], "|") != 0)
        return 0;
    if ((*command)[count].redir.out != 0) {
        fprintf(stderr, "Ambigous output redirect.\n");
        return FAILURE;
    }
    if ((!line[(*i) + 1] || is_separators(line[(*i) + 1], 0) == true) ||
        (*command)[count].cmd == NULL) {
        fprintf(stderr, "Invalid null command.\n");
        return FAILURE;
    }
    (*command)[count].redir.out = PIPE;
    (*command)[count + 1].redir.in = PIPE;
    return 0;
}