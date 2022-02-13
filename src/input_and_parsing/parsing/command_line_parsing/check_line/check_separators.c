/*
** EPITECH PROJECT, 2023
** PSU_42sh_2018
** File description:
** Created by charles,
*/

#include "parsing.h"
#include "stdio.h"
#include <string.h>
#include "my.h"

int is_separators(char *word, int opt)
{
    if (m_scmp(word, "&&", 0) == 0 || m_scmp(word, "|", 0) == 0 ||
        strcmp(word, "||") == 0)
        return true;
    if (opt == 1 && m_scmp(word, ";", 0) == 0)
        return true;
    return false;
}

int check_separators(char **line, int count)
{
    if (is_separators(line[count], 0) == false)
        return 0;
    if (count == 0 || strcmp(line[count - 1], "(") == 0 ||
        is_null_forward(line, count + 1) == true) {
        fprintf(stderr, "Invalid null command.\n");
        return FAILURE;
    }
    return SUCCESS;
}