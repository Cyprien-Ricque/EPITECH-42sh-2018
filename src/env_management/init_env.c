/*
** EPITECH PROJECT, 2019
** 42sh
** File description:
** Created by Emilien Delevoye
*/

#include <string.h>
#include <stdlib.h>
#include "my_42sh.h"
#include "parsing.h"
#include "line_edit.h"
#include "my.h"
#include <stdio.h>

char append_env_node(list_t *exe, char *env_line)
{
    int c;
    list_t *new_node = malloc(sizeof(list_t));

    if (new_node == NULL)
        return (FAILURE);
    for (c = 0; env_line[c] != '='; c++);
    new_node->names = strndup(env_line, (size_t)c);
    if (!new_node->names)
        return (FAILURE);
    new_node->value = strdup(&env_line[c + 1]);
    if (!new_node->value)
        return (FAILURE);
    new_node->next = NULL;
    new_node->link = NULL;
    exe->next = new_node;
    return (SUCCESS);
}

int detect_env_i(const exec_t *exe)
{
    int c;

    if (exe->tmp_env[0] != NULL) {
        for (c = 0; exe->tmp_env[0][c] != '='; c++);
        exe->env->names = strndup(exe->tmp_env[0], c);
        if (!exe->env->names)
            return (FAILURE);
        exe->env->value = strdup(&exe->tmp_env[0][c + 1]);
        if (!exe->env->value)
            return (FAILURE);
    } else {
        exe->env->names = NULL;
        exe->env->value = NULL;
    }
    return (SUCCESS);
}

char create_env_chained_list(exec_t *exe)
{
    list_t *tmp;

    exe->env = malloc(sizeof(list_t));
    if (!exe->env)
        return (FAILURE);
    if (detect_env_i(exe) == FAILURE)
        return (FAILURE);
    exe->env->next = NULL;
    exe->env->link = NULL;
    tmp = exe->env;
    for (int i = 1; exe->tmp_env[i] != NULL; i++) {
        if (append_env_node(tmp, exe->tmp_env[i]) == FAILURE)
            return (FAILURE);
        tmp = tmp->next;
    }
    return (SUCCESS);
}

char create_shell_cl(exec_t *exe)
{
    exe->shell = malloc(sizeof(list_t));
    if (!exe->shell)
        return (FAILURE);
    exe->shell->names = strdup("0");
    if (!exe->shell->names)
        return (FAILURE);
    exe->shell->value = strdup("42sh");
    if (!exe->shell->value)
        return (FAILURE);
    exe->shell->next = NULL;
    exe->shell->link = NULL;
    return (SUCCESS);
}

char init_env(exec_t *exe, char **env)
{
    if (env != NULL) {
        exe->tmp_env = m_arraydup((const char **) env);
        if (!exe->tmp_env)
            return (FAILURE);
        if (create_env_chained_list(exe) == FAILURE)
            return (FAILURE);
    }
    return (SUCCESS);
}