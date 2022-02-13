/*
** EPITECH PROJECT, 2018
** m_puts
** File description:
** m_puts
*/

#include <unistd.h>
#include <stddef.h>
#include "my.h"
#include <stdlib.h>
#include <stdio.h>

char *cut_int(char *str, int begin, int end)
{
    for (int i = 0; i < begin; ++i)
        str++;
    if (end != -1)
        str[end] = 0;
    return (str);
}

char *cut_char(char *str, char begin, char end)
{
    int init = m_spelen(str, begin);

    for (int i = 0; i < init; ++i)
        str++;
    str[m_spelen(str, end)] = 0;
    return (str);
}