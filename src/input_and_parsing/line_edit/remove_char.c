/*
** EPITECH PROJECT, 2019
** remove_char
** File description:
** Created by Emilien Delevoye
*/

#include <stdio.h>
#include "line_edit.h"

void move_str(char *str, int pos)
{
    for (int a = pos; str[a]; ++a) {
        str[a] = str[a + 1];
    }
    printf("\033[1D\033[K");
}

void remove_char(line_edit_t *line)
{
    --line->position;
    move_str(line->current_line, line->position);
    --line->nb_char;
}