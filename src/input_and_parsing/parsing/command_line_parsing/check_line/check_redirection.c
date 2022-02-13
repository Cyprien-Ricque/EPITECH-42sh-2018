/*
** EPITECH PROJECT, 2023
** PSU_42sh_2018
** File description:
** Created by charles,
*/

#include "parsing.h"
#include <string.h>
#include <stdio.h>

int is_redirection(char *word)
{
    if (strcmp(word, ">") == 0 || strcmp(word, "<<") == 0 ||
        strcmp(word, "<") == 0 || strcmp(word, ">>") == 0)
        return true;
    return false;
}

int is_special_char(char *word, int opt)
{
    if (is_redirection(word) == true || is_separators(word, opt) == true ||
        strcmp(word, "&") == 0 || strcmp(word, ")") == 0)
        return true;
    return false;
}

int ambigous_output(char **line, int count)
{
    int in_parentheses = false;
    int in_backsticks = false;

    for (; line[count] != NULL &&
        (strcmp(line[count], ")") != 0 && in_parentheses == false) &&
        ((strcmp(line[count], "||") != 0 && strcmp(line[count], "&&") != 0 &&
            strcmp(line[count], ";") != 0) &&
            (in_backsticks == false || in_parentheses == false)); ++count) {
        check_parentheses_backsticks(line, count, &in_parentheses,
            &in_backsticks);
        if ((strcmp(line[count], ">") == 0 || strcmp(line[count], ">>") == 0 ||
            strcmp(line[count], "|") == 0) && in_backsticks == false &&
            in_parentheses == false) {
            return true;
        }
    }
    return false;
}

int ambigous_input(char **line, int count)
{
    int in_parentheses = false;
    int in_backsticks = false;

    for (; count >= 0 &&
        (strcmp(line[count], "(") != 0 && in_parentheses == false) &&
        ((strcmp(line[count], "||") != 0 && strcmp(line[count], "&&") != 0 &&
            strcmp(line[count], ";") != 0) &&
            (in_backsticks == false || in_parentheses == false)); --count) {
        check_parentheses_backsticks(line, count, &in_parentheses,
            &in_backsticks);
        if ((strcmp(line[count], "<") == 0 || strcmp(line[count], "<<") == 0 ||
            strcmp(line[count], "|") == 0) && in_backsticks == false &&
            in_parentheses == false) {
            return true;
        }
    }
    return false;
}

int check_redirection(char **line, int count)
{
    if (is_redirection(line[count]) == false)
        return 0;
    if (line[count + 1] == NULL ||
        is_special_char(line[count + 1], 0) == true) {
        fprintf(stderr, "Missing name for redirect.\n");
        return FAILURE;
    }
    if ((strcmp(line[count], ">") == 0 || strcmp(line[count], ">>") == 0) &&
        ambigous_output(line, count + 1) == true) {
        fprintf(stderr, "Ambiguous output redirect.\n");
        return FAILURE;
    }
    if ((strcmp(line[count], "<") == 0 || strcmp(line[count], "<<") == 0) &&
        ambigous_input(line, count - 1) == true) {
        fprintf(stderr, "Ambiguous input redirect.\n");
        return FAILURE;
    }
    return SUCCESS;
}