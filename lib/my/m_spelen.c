/*
** EPITECH PROJECT, 2018
** m_spelen
** File description:
** m_spelen
*/

#include <unistd.h>

int m_spelen(char const *str, char c)
{
    int count = 0;

    if (!str)
        return (-1);
    while (str[count] && str[count] != c)
        ++count;
    return (count);
}