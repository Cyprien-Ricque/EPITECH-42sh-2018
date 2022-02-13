/*
** EPITECH PROJECT, 2018
** m_puts
** File description:
** m_puts
*/

#include <unistd.h>
#include <stddef.h>
#include "../../include/my.h"
#include <stdlib.h>

char *m_realloc(char *str, int size)
{
    char *news = malloc(sizeof(char) * (m_slen(str) + size + 1));

    if (!news)
        return (NULL);
    for (int i = 0; str[i]; ++i)
        news[i] = str[i];
    news[m_slen(str)] = 0;
    return (news);
}