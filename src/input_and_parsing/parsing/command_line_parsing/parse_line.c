/*
** EPITECH PROJECT, 2019
** PSU_42sh_2018
** File description:
** Created by charles,
*/

#include <stdio.h>
#include "parsing.h"
#include <string.h>
#include "alias.h"
#include "my.h"

int (*cmd_opt[9])(cmd_t **command, int count, char **line, int *i) =
{
    get_parenthesis, get_in_redirection, get_out_redirection, get_pipe,
    get_semicolons, get_and, get_or, get_cmd_line, is_null_cmd
};

int is_null_cmd(cmd_t **command, int count, char **line, int *i)
{
    if ((!line[(*i) + 1] || line[*i][0] == ';') && !(*command)[count].cmd) {
        fprintf(stderr, "Invalid null command.\n");
        return FAILURE;
    }
    return SUCCESS;
}

int fill_cmd_struct(cmd_t **command, int count, char **line, int *i)
{
    int r_value = 0;

    for (int j = 0; j < 9; j++) {
        r_value = cmd_opt[j](command, count, line, i);
        if (r_value == FAILURE || r_value == EXIT) {
            *command = free_cmd_struct(*command);
            return r_value;
        }
    }
    return SUCCESS;
}

int next_cmd(char **line, int *count, int i, cmd_t command)
{
    if ((is_separators(line[i], 0) == true ||
        (strcmp(line[i], ";") == 0 && line[i + 1] != NULL &&
            strcmp(line[i + 1], ";") != 0 && command.cmd != NULL))) {
        (*count)++;
        return SUCCESS;
    }
    return FAILURE;
}

int init(cmd_t **command, char **line, int nb_cmd)
{
    if (check_line(line) == FAILURE)
        return FAILURE;
    *command = init_cmd_struct(nb_cmd);
    if (*command == NULL)
        return EXIT;
    return SUCCESS;
}

int parse_line(cmd_t **command, char **line, UNUSED exec_t *exec)
{
    int count = 0;
    int nb_cmd = count_command(line);
    int r_value = 0;
    int i = 0;

    r_value = init(command, line, nb_cmd);
    if (r_value == FAILURE || r_value == EXIT)
        return r_value;
    for (i = 0; line[i] != NULL && line[i][0] == ';'; i++);
    for (; count < nb_cmd && line[i] != NULL; i++) {
        r_value = fill_cmd_struct(command, count, line, &i);
        if (r_value == FAILURE || r_value == EXIT)
            return r_value;
        next_cmd(line, &count, i, (*command)[count]);
    }
    for (int i = 0; (*command)[i].valid == true; i++)
        (*command)[i].cmd = send_new_value((*command)[i].cmd, exec);
    return 0;
}