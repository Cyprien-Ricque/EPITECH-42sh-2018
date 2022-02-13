/*
** EPITECH PROJECT, 2018
** my_strtoarray
** File description:
** my_strtoarray
*/

#include <stdlib.h>
#include "my.h"
#include <stddef.h>
#include <stdio.h>

int find_lines_spe(char *str, char c)
{
    int lines = 0;

    for (int i = 0; str && str[i]; ++i) {
        if (str[i] == c)
            ++lines;
    }
    return (lines);
}

char **malloc_a(char *str, char c)
{
    char **array = malloc(sizeof(char *) * (find_lines_spe(str, c) + 2));
    int e = 0;
    int line = 0;

    if (!array)
        return (NULL);
    for (int i = 0; str[i]; ++i) {
        if (str[i] == c) {
            array[line] = malloc(sizeof(char) * (e + 2));
            if (!array[line])
                return (NULL);
            e = 0;
            ++line;
        }
        ++e;
    }
    array[line] = malloc(sizeof(char) * (e + 2));
    if (!array[line])
        return (NULL);
    return (array);
}

void fill(char *str, char c, char **array)
{
    int y = 0;
    int x = 0;

    for (int i = 0; str[i]; ++i) {
        if (str[i] == c) {
            array[y][x] = '\0';
            y++;
            x = 0;
        } else {
            array[y][x] = str[i];
            ++x;
        }
    }
    array[y][x] = 0;
    array[y + 1] = NULL;
}

char **m_sarray(char *str, char c, bool t_free)
{
    char **array;

    if (!str)
        return (NULL);
    array = malloc_a(str, c);
    if (!array)
        return (NULL);
    fill(str, c, array);
    if (t_free == true)
        free(str);
    for (int i = 0; array[i]; ++i)
        for (int j = 0; array[i][j]; ++j)
            if (array[i][j] < 0)
                array[i][j] *= -1;
    return (array);
}