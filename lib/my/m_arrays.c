/*
** EPITECH PROJECT, 2018
** my_strtoarray
** File description:
** my_strtoarray
*/

#include <stdlib.h>
#include "my.h"
#include <stddef.h>
#include <stdio.h>

char *m_arrays(char **array, char c)
{
    char *str = malloc(sizeof(char));

    if (!array || !str)
        return (NULL);
    str[0] = 0;
    for (int i = 0; array[i]; ++i) {
        str = m_scat(str, array[i], m_slen(str), 0);
        if (!str)
            return (NULL);
        if (array[i + 1]) {
            str = m_scat(str, &c, m_slen(str), 1);
            if (!str)
                return (NULL);
        }
    }
    return (str);
}