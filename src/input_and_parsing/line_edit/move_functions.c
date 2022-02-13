/*
** EPITECH PROJECT, 2019
** move_functions
** File description:
** Created by Emilien Delevoye
*/

#include <unistd.h>
#include <sys/wait.h>
#include "line_edit.h"

void default_move(line_edit_t *line, int character, bool *do_cat)
{
    if (character != RIGHT_KEY && character != LEFT_KEY && character != 127 &&
        character != LEFT_MOVE && character != RIGHT_MOVE &&
        character != CUT_AFTER && character != PASTE && character != CLEAR &&
        character != UP_KEY && character != DOWN_KEY &&
        character != TAB_CHAR) {
        *do_cat = true;
        ++line->nb_char;
        ++line->position;
    }
}

void particular_moves(line_edit_t *line, int character)
{
    if (character == LEFT_MOVE)
        line->position = 0;
    if (character == RIGHT_MOVE)
        line->position = line->nb_char;
    if (character == CTRL_RIGHT) {
        if (line->position != line->nb_char)
            ++line->position;
        while (line->current_line[line->position] != ' ' &&
            line->position < line->nb_char)
            ++line->position;
    } else if (character == CTRL_LEFT) {
        if (line->position > 0)
            --line->position;
        while (line->current_line[line->position] != ' ' && line->position > 0)
            --line->position;
    }
}

void clear_input(int character, exec_t *exe)
{
    char *tab[2] = {"", NULL};

    if (character == CLEAR) {
        if (fork() == 0)
            execvp("clear", tab);
        else
            wait(NULL);
        prompt(exe, true);
    }
}

char move_right_left_back(line_edit_t *line, int character, exec_t *exe)
{
    if (character == TAB_CHAR)
        return (tab_character(line, exe));
    if (character == RIGHT_KEY) {
        if (line->position < line->nb_char)
            ++line->position;
    }
    if (character == LEFT_KEY) {
        if (line->position > 0)
            --line->position;
    }
    if (character == 127) {
        if (line->position > 0)
            remove_char(line);
    }
    clear_input(character, exe);
    if (history_move(character, line) == FAILURE)
        return (FAILURE);
    particular_moves(line, character);
    return (SUCCESS);
}