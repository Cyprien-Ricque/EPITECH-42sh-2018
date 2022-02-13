/*
** EPITECH PROJECT, 2019
** escape_case
** File description:
** Created by Emilien Delevoye
*/

#include <sys/ioctl.h>
#include <stdio.h>
#include <stdbool.h>
#include "line_edit.h"

bool escape_hit(line_edit_t content)
{
    int output;

    ioctl(0, TCSETS, &content.geti);
    output = getchar();
    ioctl(0, TCSETS, &content.init);
    if (output == -1) {
        return (false);
    } else {
        ungetc(output, stdin);
        return (true);
    }
}

int check_ctrl_arrow(void)
{
    int value;

    if (getchar() != ';')
        return ('A');
    if (getchar() != '5')
        return ('A');
    value = getchar();
    if (value == 'D')
        return (CTRL_LEFT);
    else if (value == 'C')
        return (CTRL_RIGHT);
    return ('A');
}

int check_characters(int input)
{
    if (input == 'A')
        return (UP_KEY);
    if (input == 'B')
        return (DOWN_KEY);
    if (input == 'C')
        return (RIGHT_KEY);
    if (input == 'D')
        return (LEFT_KEY);
    if (input == 'K')
        return (CUT_AFTER);
    if (input == 'Y')
        return (PASTE);
    if (input == '1')
        return (check_ctrl_arrow());
    return ('A');
}

int escape_case(line_edit_t content)
{
    int output;

    if (escape_hit(content) == false)
        return (ESCAPE_KEY);
    output = take_char(content);
    if (output == '[')
        return (check_characters(take_char(content)));
    while (escape_hit(content))
        take_char(content);
    return (0);
}