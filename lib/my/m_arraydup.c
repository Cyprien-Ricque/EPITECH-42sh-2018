/*
** EPITECH PROJECT, 2018
** my_strdup
** File description:
** my_strdup
*/

#include <stdlib.h>
#include "my.h"

char **m_arraydup(char const **src)
{
    char **array;

    if (!src)
        return (NULL);
    array = malloc(sizeof(char *) * (m_arraylen(src) + 1));
    if (!array)
        return (NULL);
    for (int i = 0; src[i]; ++i) {
        array[i] = m_sdup(src[i], 0);
        if (!array[i])
            return (NULL);
    }
    array[m_arraylen(src)] = NULL;
    return (array);
}