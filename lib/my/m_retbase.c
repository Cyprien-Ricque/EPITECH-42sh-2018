/*
** EPITECH PROJECT, 2018
** m_retbase
** File description:
** m_retbase
*/

#include "my.h"
#include <stdio.h>
#include <stdlib.h>

char *m_retbase(long long nb, int base)
{
    char *result = malloc(sizeof(char) * 22);
    long long nb_bis = nb < 0 ? -nb : nb;
    int i;

    if (!nb_bis || !result)
        return ("0");
    for (i = 0; nb_bis > 0; ++i) {
        result[i] = (nb_bis % base) + 48;
        if (result[i] > '9')
            result[i] += 39;
        nb_bis = nb_bis / base;
    }
    if (nb < 0)
        result[i++] = '-';
    result[i] = 0;
    result = m_revs(result);
    return (result);
}