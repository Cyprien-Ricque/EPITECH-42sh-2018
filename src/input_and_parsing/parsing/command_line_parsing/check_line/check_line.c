/*
** EPITECH PROJECT, 2023
** PSU_42sh_2018
** File description:
** Created by charles,
*/

#include "parsing.h"
#include <stdio.h>

int (*check_fct[9])(char **line, int count) =
{
    check_separators, check_redirection
};

int is_valid(char **line, int count)
{
    for (int i = 0; i < 2; i++) {
        if (check_fct[i](line, count) == FAILURE)
            return FAILURE;
    }
    return SUCCESS;
}

int check_line(char **line)
{

    if (check_pths_bckstk(line) == FAILURE)
        return FAILURE;
    for (int i = 0; line[i] != NULL; i++) {
        if (is_valid(line, i) == FAILURE)
            return FAILURE;
    }
    return SUCCESS;
}