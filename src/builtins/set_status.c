/*
** EPITECH PROJECT, 2018
** find_env_value.c
** File description:
** find env value
*/

#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include <ctype.h>
#include "my_42sh.h"
#include "my.h"
#include "execution.h"
#include "builtins.h"

char print_set(list_t *cur)
{
    if (cur->names != NULL)
        m_printf(1, "%s\t", cur->names);
    if (cur->value != NULL)
        m_printf(1, "%s\n", cur->value);
    if (cur->value == NULL && cur->names != NULL)
        m_printf(1, "\n");
    return (SUCCESS);
}

char m_print_set(cmd_t *cmd UNUSED, exec_t *exe)
{
    list_t *tmp = exe->shell;

    while (tmp != NULL) {
        if (tmp->names != NULL && isalpha(tmp->names[0]) != 0)
            print_set(tmp);
        tmp = tmp->next;
    }
    return (SUCCESS);
}

char set_error_management(cmd_t *cmd, exec_t *exe,
    const char *arg, bool *chg)
{
    (*chg) = false;
    if (isalpha(arg[0]) == 0) {
        dprintf(2, "set: Variable name must begin with a letter.\n");
        return (cmd_error(cmd, exe));
    }
    return (SUCCESS);
}

char *get_shell_var_name(const char *arg)
{
    int c;
    char *name;

    for (c = 0; arg[c] != '=' && arg[c] != '\0'; c++);
    name = strndup(arg, c);
    if (!name)
        return (NULL);
    return (name);
}

void set_node_ptr(list_t *exe, list_t *new_node)
{
    new_node->next = NULL;
    new_node->link = NULL;
    exe->next = new_node;
}