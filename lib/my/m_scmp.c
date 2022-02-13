/*
** EPITECH PROJECT, 2018
** my_strcmp
** File description:
** my_ctrcmp
*/

#include <stdio.h>
#include "my.h"

int m_scmp(char const *str1, char const *str2, char lim)
{
    if (!str1 || !str2)
        return (84);
    for (int i = 0; !((!str1[i] || str1[i] == lim) &&
        (!str2[i] || str2[i] == lim)); ++i) {
        if (str1[i] > str2[i])
            return (1);
        if (str1[i] < str2[i])
            return (-1);
    }
    return (0);
}