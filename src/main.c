/*
** EPITECH PROJECT, 2019
** 42sh
** File description:
** Created by Emilien Delevoye
*/

#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include "alias.h"
#include "execution.h"
#include "parsing.h"
#include "line_edit.h"
#include "my.h"

void set_value_parsing_error(exec_t *exe)
{
    int rv = 1;
    list_t *tmp = find_var("?", exe->shell);

    if (!tmp)
        return;
    tmp->value = m_sdup(m_retbase(rv, 10), 0);
    if (!tmp->value)
        return;
    if (tmp->link) {
        tmp->link->value = m_sdup(m_retbase(rv, 10), 0);
        if (!tmp->link->value)
            return;
    }
}

char sh(char *cmd, int UNUSED fd, exec_t *exe)
{
    int rv;
    cmd_t *cmd_s = malloc(sizeof(cmd_t));

    if (!cmd || !exe)
        return (FAILURE);
    rv = parse_line(&cmd_s, m_sarray(clean_cmd(cmd), ' ', true), exe);
    if (rv == EXIT_FAILURE)
        return FAILURE;
    if (rv != FAILURE && execution(cmd_s, exe) == FAILURE)
        return (FAILURE);
    if (rv == FAILURE)
        set_value_parsing_error(exe);
    return (SUCCESS);
}

char main_42sh(char **env)
{
    exec_t exe = {.env = NULL, .line.paperweight = NULL};
    char *cmd = NULL;

    exe.ini = malloc(sizeof(struc_s));
    if (!exe.ini)
        return (84);
    exe.ini->val = 0;
    if (init_shell(&exe, env) == FAILURE)
        return (FAILURE);
    cmd = take_entry(&exe);
    while (cmd) {
        if (sh(cmd, 1, &exe) == FAILURE)
            return (FAILURE);
        cmd = take_entry(&exe);
    }
    close(exe.history.fd);
    return ((char)m_getnb(get_value("?", exe.shell)));
}

int main(int ac, char **av UNUSED, char **env)
{
    if (ac != 1)
        return (FAILURE);
    return (main_42sh(env));
}