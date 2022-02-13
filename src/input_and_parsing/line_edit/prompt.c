/*
** EPITECH PROJECT, 2019
** prompt
** File description:
** Created by Emilien Delevoye
*/

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include "line_edit.h"
#include "execution.h"

void prompt_end(char *return_value, bool line_back, char *str1, char *str2)
{
    int value = atoi(return_value) % 255;
    printf("\033[37m╭─\033[33m%s\033[37m - \033[36m%s", str1, str2);
    if (return_value[0] == '0' && return_value[1] == '\0')
        printf("\033[37m - [\033[32m%03d\033[37m]\n", value);
    else
        printf("\033[37m - [\033[31m%03d\033[37m]\n", value);
    if (line_back == true)
        printf("╰─± \033[0m");
    else
        printf("\033[0m");
}

void prompt(exec_t *exec, bool line_back)
{
    char *str1 = get_value("USER", exec->env);
    char *str2 = getcwd(NULL, 0);
    char *return_value = get_value("?", exec->shell);

    if (!str1 || !str2 || !return_value) {
        printf("\033[37m╭─\033[33m42sh\n\033[37m");
        if (line_back == true)
            printf("╰─± \033[0m");
        else
            printf("\033[0m");
        return;
    }
    prompt_end(return_value, line_back, str1, str2);
}