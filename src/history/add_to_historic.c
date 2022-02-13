/*
** EPITECH PROJECT, 2019
** add_to_historic
** File description:
** Created by Emilien Delevoye
*/

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "my_42sh.h"

char create_if_empty(exec_t *exec, char *str)
{
    exec->history.first = malloc(sizeof(struct history_list));
    if (!exec->history.first)
        return (FAILURE);
    exec->history.last = exec->history.first;
    exec->history.first->next = NULL;
    exec->history.first->prev = NULL;
    exec->history.first->content = strdup(str);
    if (!exec->history.first->content)
        return (FAILURE);
    exec->history.first->position = 0;
    dprintf(exec->history.fd, "%04d %s\n", exec->history.last->position, str);
    return (SUCCESS);
}

char add_to_historic(char *str, exec_t *exec)
{
    if (!exec->history.last && !exec->history.first && str)
        return (create_if_empty(exec, str));
    if (!exec->history.last || exec->history.last->content != NULL || !str)
        return (SUCCESS);
    exec->history.last->content = strdup(str);
    if (!exec->history.last->content)
        return (FAILURE);
    if (exec->history.last && exec->history.last->prev)
        exec->history.last->position = exec->history.last->prev->position + 1;
    else
        exec->history.last->position = 0;
    dprintf(exec->history.fd, "%04d %s\n", exec->history.last->position, str);
    return (SUCCESS);
}