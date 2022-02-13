/*
** EPITECH PROJECT, 2018
** which.c
** File description:
** which builtin
*/

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include "my_42sh.h"
#include "my.h"
#include "execution.h"
#include "builtins.h"

int print_which_valid_buffer(bool **exist, const char *buffer)
{
    m_printf(1, "%s\n", buffer);
    (**exist) = true;
    return (SUCCESS);
}

int browse_which_path(exec_t *exe, char *cmd, bool *exist)
{
    char **path;
    char buffer[PATH_MAX];

    if (find_env_value(exe, "PATH") == NULL)
        return (FAILURE);
    if (find_env_value(exe, "PATH")[0] == NO_REF
    || find_env_value(exe, "PATH")[0] == EMPTY) {
        (*exist) = false;
        return (SUCCESS);
    }
    path = m_sarray(find_env_value(exe, "PATH"), ':', false);
    if (!path)
        return (FAILURE);
    for (int y = 0; path[y] != NULL; y++) {
        set_full_path_buffer(cmd, path, buffer, y);
        if (access(buffer, F_OK | X_OK) == SUCCESS)
            return (print_which_valid_buffer(&exist, buffer));
    }
    return (SUCCESS);
}

int print_which_builtin_ref(cmd_t *cmd, int y, bool *exist)
{
    int i;

    for (i = 0; builtin[i] != NULL; i++) {
        if (strcmp(cmd->cmd[y], builtin[i]) == SUCCESS) {
            m_printf(1, "%s: shell built-in command.\n", cmd->cmd[y]);
            (*exist) = true;
            return (SUCCESS);
        }
    }
    return (ERROR);
}

int exe_which_loop(cmd_t *cmd, exec_t *exe, bool *error)
{
    bool exist;

    for (int y = 1; cmd->cmd[y] != NULL; y++) {
        exist = false;
        if (cmd->cmd[y][0] == '/') {
            dprintf(2, "/: Command not found.\n");
            (*error) = true;
            continue;
        }
        if (print_which_builtin_ref(cmd, y, &exist) == SUCCESS
        || print_which_alias_ref(cmd, exe, y, &exist) == SUCCESS)
            continue;
        if (browse_which_path(exe, cmd->cmd[y], &exist) == FAILURE)
            return (FAILURE);
        if (exist == false) {
            dprintf(2, "%s: Command not found.\n", cmd->cmd[y]);
            (*error) = true;
        }
    }
    return (SUCCESS);
}

char m_which(cmd_t *cmd, exec_t *exe)
{
    bool error = false;

    if (!cmd->cmd[1]) {
        dprintf(2, "which: Too few arguments.\n");
        return (cmd_error(cmd, exe));
    }
    if (exe_which_loop(cmd, exe, &error) == FAILURE)
        return (FAILURE);
    if (error == true)
        return (cmd_error(cmd, exe));
    return (SUCCESS);
}