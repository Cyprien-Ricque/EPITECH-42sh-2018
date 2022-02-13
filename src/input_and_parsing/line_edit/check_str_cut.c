/*
** EPITECH PROJECT, 2019
** check_str_cut
** File description:
** Created by Emilien Delevoye
*/

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "line_edit.h"

char *my_strcat_cut(char const *first, char const *second, int position)
{
    int size = strlen(first) + strlen(second);
    char *output = malloc(sizeof(char) * (size + 3));
    int tot = 0;
    int tmp;

    if (!output)
        return (NULL);
    for (tmp = 0; tmp != position && first[tmp]; ++tmp) {
        output[tot] = first[tmp];
        output[++tot] = '\0';
    }
    for (int a = 0; second[a]; ++a) {
        output[tot] = second[a];
        output[++tot] = '\0';
    }
    for (; first[tmp]; ++tmp) {
        output[tot] = first[tmp];
        output[++tot] = '\0';
    }
    return (output);
}

char check_str_cut(line_edit_t *line, int character, line_t *content)
{
    if (character == CUT_AFTER) {
        content->paperweight = strdup(line->current_line + line->position);
        line->current_line[line->position] = '\0';
        line->position = strlen(line->current_line);
    } else if (character == PASTE && content->paperweight) {
        line->current_line = my_strcat_cut(line->current_line,
            content->paperweight, line->position);
        if (!line->current_line)
            return (FAILURE);
        line->nb_char += strlen(content->paperweight);
        line->position += strlen(content->paperweight);
    }
    return (SUCCESS);
}