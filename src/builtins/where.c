/*
** EPITECH PROJECT, 2018
** where.c
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

void set_full_path_buffer(const char *cmd, char *const *path, char *buffer,
    int y)
{
    memset(buffer, '\0', PATH_MAX);
    strcat(buffer, path[y]);
    strcat(buffer, "/");
    strcat(buffer, cmd);
}

int browse_where_path(exec_t *exe, char *cmd, bool *exist)
{
    char **path;
    char buffer[PATH_MAX];

    if (find_env_value(exe, "PATH") == NULL)
        return (FAILURE);
    if (find_env_value(exe, "PATH")[0] == NO_REF ||
        find_env_value(exe, "PATH")[0] == EMPTY)
        return (SUCCESS);
    path = m_sarray(find_env_value(exe, "PATH"), ':', false);
    if (!path)
        return (FAILURE);
    for (int y = 0; path[y] != NULL; y++) {
        set_full_path_buffer(cmd, path, buffer, y);
        if (access(buffer, F_OK | X_OK) == SUCCESS) {
            m_printf(1, "%s\n", buffer);
            (*exist) = true;
        }
    }
    return (SUCCESS);
}

void print_where_builtin_ref(cmd_t *cmd, int y, bool *exist)
{
    int i;

    for (i = 0; builtin[i] != NULL; i++) {
        if (strcmp(cmd->cmd[y], builtin[i]) == SUCCESS) {
            m_printf(1, "%s is a shell built-in\n", cmd->cmd[y]);
            (*exist) = true;
        }
    }
}

int exe_where_loop(cmd_t *cmd, exec_t *exe, bool *error)
{
    bool exist;

    for (int y = 1; cmd->cmd[y] != NULL; y++) {
        exist = false;
        if (cmd->cmd[y][0] == '/') {
            dprintf(2, "where: / in command makes no sense\n");
            (*error) = true;
            continue;
        }
        print_where_builtin_ref(cmd, y, &exist);
        print_where_alias_ref(cmd, exe, y, &exist);
        if (browse_where_path(exe, cmd->cmd[y], &exist) == FAILURE)
            return (FAILURE);
        if (exist == false)
            (*error) = true;
    }
    return (SUCCESS);
}

char m_where(cmd_t *cmd, exec_t *exe)
{
    bool error = false;

    if (!cmd->cmd[1]) {
        dprintf(2, "where: Too few arguments.\n");
        return (cmd_error(cmd, exe));
    }
    if (exe_where_loop(cmd, exe, &error) == FAILURE)
        return (FAILURE);
    if (error == true)
        return (cmd_error(cmd, exe));
    else
        return (SUCCESS);
}