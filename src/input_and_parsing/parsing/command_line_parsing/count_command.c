/*
** EPITECH PROJECT, 2019
** PSU_42sh_2018
** File description:
** Created by charles,
*/

#include <stdbool.h>
#include <unistd.h>
#include <string.h>
#include <stdio.h>

static int is_separator(char **command, int i)
{
    if (strcmp(command[i], ";") == 0 &&
        (command[i + 1] != NULL && strcmp(command[i + 1], ";") != 0))
        return true;
    return false;
}

void check_parentheses_backsticks(char **command, int i, int *in_parentheses,
    int *in_backsticks)
{
    if (strcmp(command[i], "(") == 0 && *in_backsticks == false)
        (*in_parentheses) += true;
    if (strcmp(command[i], ")") == 0 && *in_backsticks == false)
        (*in_parentheses) -= true;
    if ((*in_backsticks) == false && strcmp(command[i], "`") == 0)
        (*in_backsticks) += true;
    else if ((*in_backsticks) == true && strcmp(command[i], "`") == 0)
        (*in_backsticks) -= true;
}

int count_command(char **command)
{
    int i = 0;
    int n = 1;
    int in_parentheses = false;
    int in_backsticks = false;

    if (!command)
        return 0;
    for (i = 0; command[i] != NULL && command[i][0] == ';'; i++);
    if (command[i] == NULL)
        return 0;
    for (; command[i] != NULL; i++) {
        check_parentheses_backsticks(command, i, &in_parentheses,
            &in_backsticks);
        if ((strcmp(command[i], "||") == 0 || strcmp(command[i], "&&") == 0 ||
            is_separator(command, i) == true || strcmp(command[i], "|") == 0) &&
            in_parentheses == false && in_backsticks == false) {
            n++;
        }
    }
    return n;
}