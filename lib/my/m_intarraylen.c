/*
** EPITECH PROJECT, 2018
** m_slen
** File description:
** m_slen
*/

#include <unistd.h>

int m_intarraylen(int *array)
{
    int count = 0;

    if (!array)
        return (0);
    while (array[count] != -1)
        ++count;
    return (count);
}