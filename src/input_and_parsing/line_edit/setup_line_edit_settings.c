/*
** EPITECH PROJECT, 2019
** setup_line_edit_settings
** File description:
** Created by Emilien Delevoye
*/

#include <stdlib.h>
#include <sys/ioctl.h>
#include "line_edit.h"

line_edit_t setup_settings(line_edit_t *output)
{
    ioctl(0, TCGETS, &(*output).init);
    ioctl(0, TCGETS, &(*output).getc);
    ioctl(0, TCGETS, &(*output).geti);
    (*output).getc.c_lflag &= ~ICANON;
    (*output).getc.c_lflag &= ~ECHO;
    (*output).getc.c_cc[VMIN] = 1;
    (*output).getc.c_cc[VTIME] = 0;
    (*output).geti.c_lflag &= ~ICANON;
    (*output).geti.c_lflag &= ~ECHO;
    (*output).geti.c_cc[VMIN] = 0;
    (*output).geti.c_cc[VTIME] = 1;
    return (*output);
}

line_edit_t setup_end_node_hist(exec_t *exec, line_edit_t *output)
{
    (*output).head = exec->history.last;
    if ((*output).head && (*output).head->content != NULL) {
        (*output).head->next = malloc(sizeof(struct history_list));
        if (!(*output).head->next) {
            (*output).current_line = NULL;
            return (*output);
        }
        (*output).head->next->prev = (*output).head;
        (*output).head = (*output).head->next;
        (*output).head->content = NULL;
        (*output).head->position = 0;
        (*output).head->next = NULL;
        exec->history.last = (*output).head;
    }
    return (*output);
}

line_edit_t init_struct(exec_t *exec)
{
    line_edit_t output;

    output.nb_char = 0;
    output.position = 0;
    output.current_line = malloc(sizeof(char) * MALLOC_INPUT);
    if (!output.current_line) {
        output.current_line = NULL;
        return (output);
    }
    output.current_line[0] = '\0';
    output = setup_settings(&output);
    output = setup_end_node_hist(exec, &output);
    return (output);
}