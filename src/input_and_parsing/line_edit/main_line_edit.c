/*
** EPITECH PROJECT, 2019
** main_line_edit
** File description:
** Created by Emilien Delevoye
*/

#include <sys/ioctl.h>
#include <stdio.h>
#include <unistd.h>
#include <stdio.h>
#include "my.h"
#include "lib.h"
#include "my_42sh.h"
#include "line_edit.h"
#include "execution.h"
#include "history.h"

int take_char(line_edit_t content)
{
    int output;

    ioctl(0, TCSETS, &content.getc);
    output = getchar();
    ioctl(0, TCSETS, &content.init);
    return (output);
}

int check_char(line_edit_t content)
{
    int output = take_char(content);

    if (output == ESCAPE_KEY)
        return (escape_case(content));
    else
        return (output);
}

char *read_input(exec_t *exec)
{
    int character;
    line_edit_t line = init_struct(exec);
    bool do_cat;

    prompt(exec, true);
    if (line.current_line == NULL)
        return (NULL);
    while ((character = check_char(line)) != -1) {
        do_cat = false;
        if (move_right_left_back(&line, character, exec) == FAILURE)
            return (NULL);
        if (character == '\n')
            return (line.current_line);
        else if (character == 4 || character == 0)
            return (NULL);
        default_move(&line, character, &do_cat);
        if (disp_line(&line, character, do_cat, &exec->line) == FAILURE)
            return (NULL);
    }
    return (line.current_line);
}

char *take_entry(exec_t *exec)
{
    char *save;

    if (isatty(0)) {
        save = read_input(exec);
        printf("\n");
        if (add_to_historic(save, exec) == FAILURE)
            return (NULL);
        return (save);
    } else {
        return (gnl(0));
    }
}