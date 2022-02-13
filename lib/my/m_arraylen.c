/*
** EPITECH PROJECT, 2018
** m_slen
** File description:
** m_slen
*/

#include <unistd.h>

int m_arraylen(char **src)
{
    int count = 0;

    if (!src)
        return (0);
    while (src[count])
        ++count;
    return (count);
}