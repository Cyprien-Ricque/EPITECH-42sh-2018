/*
** EPITECH PROJECT, 2019
** link_for_chained_list.c
** File description:
** link cl management
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

char link_shell_var_with_env_var(list_t *tmp, exec_t *exe, char *v_name,
    char *env_name)
{
    list_t *link;
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
    tmp = tmp->next;
    tmp->link = (find_env_value(exe, env_name) == NULL || find_env_value(exe,
        env_name)[0] == NO_REF ? NULL : find_env_node(exe, env_name));
    link = find_env_node(exe, env_name);
    if (link != NULL)
        link->link = tmp;
    return (SUCCESS);
}

char link_and_create(list_t **tmp, exec_t *exe)
{
    if (link_shell_var_with_env_var((*tmp), exe, "term=", "TERM") == FAILURE)
        return (FAILURE);
    (*tmp) = (*tmp)->next;
    if (link_shell_var_with_env_var((*tmp), exe, "user=", "USER") == FAILURE)
        return (FAILURE);
    (*tmp) = (*tmp)->next;
    if (link_shell_var_with_env_var((*tmp), exe, "home=", "HOME") == FAILURE)
        return (FAILURE);
    (*tmp) = (*tmp)->next;
    if (create_shell_var_with_env_var((*tmp), exe, "cwd=", "PWD") == FAILURE)
        return (FAILURE);
    (*tmp) = (*tmp)->next;
    if (create_shell_var_with_env_var((*tmp), exe, "LANG=", "LANG") == FAILURE)
        return (FAILURE);
    (*tmp) = (*tmp)->next;
    if (create_shell_var_with_env_var((*tmp), exe, "~", "HOME") == FAILURE)
        return (FAILURE);
    return (SUCCESS);
}

char link_two_shell_var(list_t *tmp, exec_t *exe, char *name,
    char *o_name)
{
    list_t *link;

    tmp = find_shell_node(exe, name);
    link = find_shell_node(exe, o_name);
    tmp->link = link;
    if (link != NULL)
        link->link = tmp;
    return (SUCCESS);
}