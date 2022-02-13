/*
** EPITECH PROJECT, 2023
** PSU_42sh_2018
** File description:
** Created by charles,
*/

#include "parsing.h"
#include "stdio.h"
#include <string.h>

int check_pths_bckstk(char **line)
{
    int in_parentheses = false;
    int in_backsticks = false;

    for (int i = 0; line[i] != NULL; i++)
        check_parentheses_backsticks(line, i, &in_parentheses, &in_backsticks);
    if (in_backsticks != false) {
        fprintf(stderr, "Unmatched \'`\'\n");
        return FAILURE;
    }
    if (in_parentheses > false) {
        fprintf(stderr, "Unmatched (\'s\n");
        return FAILURE;
    } else if (in_parentheses < false) {
        fprintf(stderr, "Unmatched )\'s\n");
        return FAILURE;
    }
    return SUCCESS;
}

int in_parentheses_check(char **line, int count)
{
    if (strcmp(line[count], "(") != 0)
        return 0;
    return SUCCESS;
}

