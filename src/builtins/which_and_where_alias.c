/*
** EPITECH PROJECT, 2018
** which_and_where_alias.c
** File description:
** where builtin
*/

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <string.h>
#include "my_42sh.h"
#include "my.h"
#include "execution.h"
#include "builtins.h"

void print_which_a_ref(char *cmd, char **alias)
{
    m_printf(1, "%s: \t aliased to ", cmd);
    for (int i = 0; alias[i] != NULL; i++) {
        if (alias[i + 1] == NULL)
            m_printf(1, "%s", alias[i]);
        else
            m_printf(1, "%s ", alias[i]);
    }
    m_printf(1, "\n");
}

int print_which_alias_ref(cmd_t *cmd, exec_t *exe, int y, bool *exist)
{
    for (struc_s *tmp = exe->ini; tmp != NULL; tmp = tmp->next) {
        if (tmp->cmp != NULL && strcmp(cmd->cmd[y], tmp->cmp) == SUCCESS) {
            print_which_a_ref(tmp->cmp, tmp->new);
            (*exist) = true;
            return (SUCCESS);
        }
    }
    return (ERROR);
}

void print_where_a_ref(char *cmd, char **alias)
{
    m_printf(1, "%s is aliased to ", cmd);
    for (int i = 0; alias[i] != NULL; i++) {
        if (alias[i + 1] == NULL)
            m_printf(1, "%s", alias[i]);
        else
            m_printf(1, "%s ", alias[i]);
    }
    m_printf(1, "\n");
}

int print_where_alias_ref(cmd_t *cmd, exec_t *exe, int y, bool *exist)
{
    for (struc_s *tmp = exe->ini; tmp != NULL; tmp = tmp->next) {
        if (tmp->cmp != NULL && strcmp(cmd->cmd[y], tmp->cmp) == SUCCESS) {
            print_where_a_ref(tmp->cmp, tmp->new);
            (*exist) = true;
        }
    }
    return (SUCCESS);
}