/*
** EPITECH PROJECT, 2018
** m_slen
** File description:
** m_slen
*/

#include <unistd.h>

int m_slen(char const *str)
{
    int count = 0;

    if (!str)
        return (0);
    while (str[count])
        ++count;
    return (count);
}