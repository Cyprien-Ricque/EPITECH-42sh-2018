/*
** EPITECH PROJECT, 2018
** m_scat
** File description:
** m_scat
*/

#include <stdlib.h>
#include "../../include/my.h"
#include <stdio.h>

void free_it(char **dest, char *src, char t_free)
{
    if (t_free == FIRST || t_free == BOTH)
        free_array(dest);
    if (t_free == SECOND || t_free == BOTH)
        free(src);
}

char **m_arraycat(char **dest, char *src, int pos, char t_free)
{
    char **new_array;

    if (!dest || !src)
        return (NULL);
    new_array = malloc(sizeof(char *) * (m_arraylen((const char **)dest) + 2));
    if (!new_array)
        return (NULL);
    for (int i = 0; i <= m_arraylen((const char **)dest); ++i) {
        i < pos ? new_array[i] = m_sdup(dest[i], 0) : NULL;
        i == pos ? new_array[i] = m_sdup(src, 0) : NULL;
        i + pos < m_arraylen((const char **)dest) ? new_array[i + pos +
            1] = m_sdup(dest[i + pos], 0) : NULL;
    }
    new_array[m_arraylen((const char **)dest) + 1] = NULL;
    free_it(dest, src, t_free);
    return (new_array);
}