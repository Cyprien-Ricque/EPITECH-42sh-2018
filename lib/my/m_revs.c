/*
** EPITECH PROJECT, 2018
** m_retbase
** File description:
** m_retbase
*/

#include "my.h"
#include <stdio.h>
#include <stdlib.h>

char *m_revs(char *str)
{
    char tmp;
    int i = 0;

    if (!str)
        return (NULL);
    while (i < m_slen(str) / 2) {
        tmp = str[m_slen(str) - i - 1];
        str[m_slen(str) - i - 1] = str[i];
        str[i] = tmp;
        ++i;
    }
    return (str);
}