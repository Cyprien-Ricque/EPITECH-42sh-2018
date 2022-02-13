/*
** EPITECH PROJECT, 2023
** PSU_42sh_2018
** File description:
** Created by charles,
*/

#include "parsing.h"
#include <stdio.h>
#include <string.h>

int is_null_forward(char **line, int i)
{
    if (line[i] != NULL && is_separators(line[i], 1) == false)
        return false;
    return true;
}