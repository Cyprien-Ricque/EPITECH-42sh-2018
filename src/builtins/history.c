/*
** EPITECH PROJECT, 2018
** history.c
** File description:
** history builtin
*/

#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include <ctype.h>
#include <unistd.h>
#include "execution.h"
#include "my_42sh.h"
#include "my.h"
#include "builtins.h"

char m_history(cmd_t *cmd UNUSED, exec_t *exe)
{
    list_history_t *tmp = exe->history.first;

    if (!tmp)
        return (SUCCESS);
    for (; tmp != NULL; tmp = tmp->next)
        if (tmp->position || tmp->content)
            m_printf(1, " %5d  %s\n", tmp->position, tmp->content);
    return (SUCCESS);
}