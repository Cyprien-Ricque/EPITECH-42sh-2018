/*
** EPITECH PROJECT, 2023
** PSU_42sh_2018
** File description:
** Created by charles,
*/

#include "parsing.h"
#include "my.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int get_cmd_line(cmd_t **command, int count, char **line, int *i)
{
    if (!(*command)[count].cmd &&
        ((*i >= 1 && is_redirection(line[(*i) - 1]) == false &&
            is_special_char(line[*i], 1) == false) ||
            (*i == 0 && is_special_char(line[*i], 1) == false))) {
        (*command)[count].cmd = malloc(sizeof(char *) * 2);
        if (!(*command)[count].cmd)
            return EXIT;
        (*command)[count].cmd[0] = strdup(line[*i]);
        if (!(*command)[count].cmd[0])
            return EXIT;
        (*command)[count].cmd[1] = NULL;
    } else if ((*command)[count].cmd != NULL &&
        ((is_special_char(line[*i], 1) == false || line[*i][0] == '!')&&
            (*i >= 1 && is_redirection(line[(*i) - 1]) == false))) {
        (*command)[count].cmd = m_arraycat((*command)[count].cmd, line[*i],
            m_arraylen((const char **)(*command)[count].cmd), FIRST);
        if (!(*command)[count].cmd)
            return EXIT;
    }
    return 0;
}