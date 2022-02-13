/*
** EPITECH PROJECT, 2018
** m_puts
** File description:
** m_puts
*/

#include <unistd.h>
#include <stddef.h>
#include "my.h"

int m_puts(char const *str, int s)
{
    if (!str)
        return (-1);
    write(s, str, (size_t)m_slen(str));
    return (0);
}