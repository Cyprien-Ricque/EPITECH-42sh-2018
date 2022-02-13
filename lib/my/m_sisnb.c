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
#include <stdio.h>

char m_sisnb(char *str, int neg)
{
    for (int i = 0; str[i]; ++i)
        if (!((str[i] >= '0' && str[i] <= '9') ||
            (str[i] == '-' && neg == RANDOM && i == 0 && str[1])))
            return (FAILURE);
    return (SUCCESS);
}