/*
** EPITECH PROJECT, 2019
** 42sh
** File description:
** Created by Emilien Delevoye
*/

#include <string.h>
#include <stdlib.h>
#include "execution.h"
#include "parsing.h"
#include "line_edit.h"
#include "my.h"
#include <stdio.h>

char *get_value(char *to_find, struct list_vars *head)
{
    if (!to_find || !head)
        return (NULL);
    for (list_t *tmp = head; tmp; tmp = tmp->next)
        if (!m_scmp(to_find, tmp->names, 0))
            return (tmp->value);
    return (NULL);
}