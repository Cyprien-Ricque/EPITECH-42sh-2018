/*
** EPITECH PROJECT, 2019
** new_history
** File description:
** Created by Emilien Delevoye
*/

#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <string.h>
#include "history.h"

bool start_is_num(char const *str)
{
    for (int a = 0; a != 4; ++a) {
        if (str[a] > '9' || str[a] < '0')
            return (false);
    }
    return (true);
}

void setup_ptr_history(exec_t *exec, list_history_t *current)
{
    if (exec->history.first == NULL) {
        exec->history.first = current;
        exec->history.last = current;
        current->prev = NULL;
        current->next = NULL;
    } else {
        exec->history.last->next = current;
        current->prev = exec->history.last;
        exec->history.last = current;
    }
}

char setup_node_history(exec_t *exec, list_history_t *current, char *str)
{
    if (strlen(str) < 6 || start_is_num(str) == false || str[4] != ' ') {
        free(current);
        return (SUCCESS);
    }
    str[4] = '\0';
    current->position = atoi(str);
    current->content = strdup(str + 5);
    if (!current->content)
        return (FAILURE);
    free(str);
    setup_ptr_history(exec, current);
    return (SUCCESS);
}

char init_content_history(exec_t *exec)
{
    char *str = get_next_line(exec->history.fd);
    list_history_t *current;

    while (str) {
        current = malloc(sizeof(list_history_t));
        if (!current)
            return (FAILURE);
        if (setup_node_history(exec, current, str) == FAILURE)
            return (FAILURE);
        str = get_next_line(exec->history.fd);
    }
    return (SUCCESS);
}

char init_history(exec_t *exec)
{
    exec->history.first = NULL;
    exec->history.last = NULL;
    exec->history.fd = open(".42sh_history", O_CREAT | O_RDWR, 0644);
    if (exec->history.fd < 0)
        return (SUCCESS);
    if (init_content_history(exec) == FAILURE)
        return (FAILURE);
    return (SUCCESS);
}