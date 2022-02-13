/*
** EPITECH PROJECT, 2018
** my_strdup
** File description:
** my_strdup
*/

#include <stdlib.h>
#include <stdio.h>
#include "my.h"

char *m_sdup(char const *src, char ch)
{
    char *str;
    int c;

    if (!src)
        return (NULL);
    str = malloc(sizeof(char) * (m_slen(src) + 1));
    if (!str)
        return (NULL);
    for (c = 0; c < m_slen(src) && src[c] != ch; ++c)
        str[c] = src[c];
    str[c] = '\0';
    return (str);
}