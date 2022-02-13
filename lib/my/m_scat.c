/*
** EPITECH PROJECT, 2018
** m_scat
** File description:
** m_scat
*/

#include <stdlib.h>
#include "my.h"
#include <stdio.h>

char *m_scat(char *dest, char *src, int pos, int n)
{
    char *new_str;

    if (!dest || !src)
        return (NULL);
    new_str = malloc(
        sizeof(char) * (m_slen(dest) + 1 + (n == 0 ? m_slen(src) : n)));
    if (!new_str)
        return (NULL);
    for (int i = 0; i < m_slen(dest) + (n == 0 ? m_slen(src) : n); ++i) {
        new_str[i] = i < pos ? dest[i] : new_str[i];
        i < (n == 0 ? m_slen(src) : n) ? new_str[i + pos] = src[i] : 1;
        pos + i < m_slen(dest) ? new_str[i + pos +
            (n == 0 ? m_slen(src) : n)] = dest[pos + i] : 1;
    }
    new_str[m_slen(dest) + (n == 0 ? m_slen(src) : n)] = 0;
    return (new_str);
}