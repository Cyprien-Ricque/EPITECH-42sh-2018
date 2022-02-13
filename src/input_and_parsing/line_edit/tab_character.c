/*
** EPITECH PROJECT, 2019
** tab_character
** File description:
** Created by Emilien Delevoye
*/

#include <dirent.h>
#include <sys/types.h>
#include <stdlib.h>
#include <stdio.h>
#include "line_edit.h"

char tab_character(line_edit_t *line UNUSED, exec_t *exe)
{
    DIR *current = opendir(".");
    struct dirent *result;
    char *str;

    if (current == NULL)
        return (FAILURE);
    printf("\n");
    result = readdir(current);
    while (result != NULL) {
        str = result->d_name;
        if (result->d_name[0] != '.')
            printf("%s   ", str);
        result = readdir(current);
    }
    printf("\n");
    prompt(exe, false);
    return (SUCCESS);
}