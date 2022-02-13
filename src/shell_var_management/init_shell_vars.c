/*
** EPITECH PROJECT, 2019
** 42sh
** File description:
** Created by Emilien Delevoye
*/

#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <stdlib.h>
#include "execution.h"
#include "parsing.h"
#include "line_edit.h"
#include "my.h"
#include "builtins.h"

char create_shell_var_with_env_var(list_t *tmp, exec_t *exe, char *v_name,
    char *env_name)
{
    char *s_name = malloc(sizeof(char) * (strlen(v_name) +
        strlen((find_env_value(exe, env_name) == NULL || find_env_value(exe,
            env_name)[0] == NO_REF) ? "0" :
            (find_env_value(exe, env_name))) + 2));

    if (!s_name)
        return (FAILURE);
    strcpy(s_name, v_name);
    if (add_shell_node(tmp, strcat(s_name, (find_env_value(exe, env_name) ==
    NULL || find_env_value(exe, env_name)[0] == NO_REF ? "\0" :
    find_env_value(exe, env_name)))) == FAILURE)
        return (FAILURE);
    return (SUCCESS);
}

char init_add_shell(list_t **tmp)
{
    if (add_shell_node((*tmp), "?=0") == FAILURE)
        return (FAILURE);
    (*tmp) = (*tmp)->next;
    if (add_shell_node((*tmp), "status=0") == FAILURE)
        return (FAILURE);
    (*tmp) = (*tmp)->next;
    if (add_shell_node((*tmp), "!=0") == FAILURE)
        return (FAILURE);
    (*tmp) = (*tmp)->next;
    if (add_shell_node((*tmp), "shell=42sh") == FAILURE)
        return (FAILURE);
    (*tmp) = (*tmp)->next;
    if (add_shell_node((*tmp), "42sh=1.0.0") == FAILURE)
        return (FAILURE);
    return (SUCCESS);
}

char init_v_shell(exec_t *exe)
{
    list_t *tmp;
    char tty_n[PATH_MAX];

    if (create_shell_cl(exe) == FAILURE)
        return (FAILURE);
    tmp = exe->shell;
    if (link_and_create(&tmp, exe) == FAILURE)
        return (FAILURE);
    tmp = tmp->next;
    if (init_add_shell(&tmp) == FAILURE)
        return (FAILURE);
    if (link_two_shell_var(tmp, exe, "?", "status") == FAILURE)
        return (FAILURE);
    if (isatty(0) == 0)
        return (SUCCESS);
    tmp = tmp->next;
    strcat(memset(tty_n, '\0', PATH_MAX), "tty=");
    if (add_shell_node(tmp, strcat(tty_n, ttyname(0))) == FAILURE)
        return (FAILURE);
    return (SUCCESS);
}