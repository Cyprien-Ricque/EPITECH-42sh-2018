/*
** EPITECH PROJECT, 2019
** disp_line
** File description:
** Created by Emilien Delevoye
*/

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "my_42sh.h"
#include "line_edit.h"

char *realloc_line(char *str)
{
    char *output;
    int len = strlen(str);

    output = malloc(sizeof(char) * (len + 3));
    if (!output)
        return (NULL);
    *output = '\0';
    for (int a = 0; str[a]; ++a) {
        output[a] = str[a];
        output[a + 1] = '\0';
    }
    free(str);
    return (output);
}

char set_char(line_edit_t *line, char character)
{
    char tmp[2] = {character, 0};

    line->current_line = realloc_line(line->current_line);
    if (!line->current_line)
        return (FAILURE);
    if (line->nb_char == line->position) {
        strcat(line->current_line, tmp);
        return (SUCCESS);
    }
    line->current_line[line->nb_char] = '\0';
    line->current_line[line->nb_char + 1] = '\0';
    for (unsigned int a = line->nb_char; a != line->position - 1; --a)
        line->current_line[a] = line->current_line[a - 1];
    line->current_line[line->position - 1] = character;
    return (SUCCESS);
}

char disp_line(line_edit_t *line, int character, bool do_cat, line_t *content)
{
    if (check_str_cut(line, character, content) == FAILURE)
        return (FAILURE);
    if (do_cat == true) {
        if (set_char(line, character) == FAILURE)
            return (FAILURE);
    }
    for (int a = line->position; a >= -100; --a)
        printf("\033[1D");
    for (unsigned int a = line->nb_char; a != 0; --a)
        printf("\033[1D\033[K");
    printf("╰─± %s", line->current_line);
    if (character == CUT_AFTER)
        line->nb_char = line->position;
    for (unsigned int a = 0; a != line->nb_char - line->position; ++a)
        printf("\033[1D");
    fflush(stdout);
    return (SUCCESS);
}