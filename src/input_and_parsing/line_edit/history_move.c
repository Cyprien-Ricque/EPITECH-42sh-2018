/*
** EPITECH PROJECT, 2019
** history_move
** File description:
** Created by Emilien Delevoye
*/

#include <string.h>
#include <unistd.h>
#include <stdio.h>
#include "line_edit.h"
#include "my_42sh.h"

char up_historic_move(line_edit_t *line)
{
    if (!line->head) {
        write(1, "\a", 1);
        return (SUCCESS);
    }
    if (line->head->prev)
        line->head = line->head->prev;
    if (!line->head) {
        write(1, "\a", 1);
        return (SUCCESS);
    }
    if (!line->head->next || !line->head->next->next)
        line->dup_current_line = line->current_line;
    if (!line->head->content)
        return (SUCCESS);
    line->current_line = strdup(line->head->content);
    if (!line->current_line)
        return (FAILURE);
    line->nb_char = strlen(line->current_line);
    line->position = line->nb_char;
    return (SUCCESS);
}

char setup_return_to_or(line_edit_t *line)
{
    line->current_line = line->dup_current_line;
    for (int a = line->position; a >= -100; --a)
        printf("\033[1D");
    for (unsigned int a = 100; a != 0; --a)
        printf("\033[1D\033[K");
    line->nb_char = strlen(line->current_line);
    line->position = line->nb_char;
    write(1, "\a", 1);
    return (SUCCESS);
}

char down_historic_move(line_edit_t *line)
{
    if (!line->head) {
        write(1, "\a", 1);
        return (SUCCESS);
    }
    if (line->head->next)
        line->head = line->head->next;
    if (!line->head || !line->head->next)
        return (setup_return_to_or(line));
    if (!line->head->content)
        return (SUCCESS);
    line->current_line = strdup(line->head->content);
    if (!line->current_line)
        return (FAILURE);
    line->nb_char = strlen(line->current_line);
    line->position = line->nb_char;
    return (SUCCESS);
}

char history_move(int character, line_edit_t *line)
{
    if (character == UP_KEY)
        return (up_historic_move(line));
    else if (character == DOWN_KEY)
        return (down_historic_move(line));
    return (SUCCESS);
}