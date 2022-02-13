/*
** EPITECH PROJECT, 2018
** m_puts
** File description:
** m_puts
*/

#include <unistd.h>
#include <stddef.h>
#include "my.h"
#include <stdlib.h>

char m_cisnb(char c, int neg)
{
    if (!((c >= '0' && c <= '9') ||
        (c == '-' && neg == RANDOM)))
        return (FAILURE);
    return (SUCCESS);
}