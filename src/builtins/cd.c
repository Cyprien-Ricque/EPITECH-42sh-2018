/*
** EPITECH PROJECT, 2018
** 42sh
** File description:
** cd
*/

#include <unistd.h>
#include <stdlib.h>
#include <errno.h>
#include <memory.h>
#include <stdio.h>
#include <limits.h>
#include <unistd.h>
#include "execution.h"
#include "my.h"
#include "builtins.h"

char update_pwd(exec_t *exe, const char *pwd)
{
    list_t *node = find_env_node(exe, "PWD");

    if (node == NULL)
        return (ERROR);
    node->value = strdup(pwd);
    if (!node->value)
        return (FAILURE);
    if (node->link != NULL) {
        node->link->value = strdup(pwd);
        if (!node->link->value)
            return (FAILURE);
    }
    return (SUCCESS);
}

int my_back_cd(char buffer[PATH_MAX], char *old_pwd, cmd_t *cmd,
    exec_t *exe)
{
    if (old_pwd[0] == '\0') {
        dprintf(2, ": No such file or directory.\n");
        return (cmd_error(cmd, exe));
    }
    else if (chdir(old_pwd) == -1) {
        dprintf(2, "%s: %s.\n", old_pwd, strerror(errno));
        return (cmd_error(cmd, exe));
    }
    strcpy(old_pwd, buffer);
    getcwd(buffer, PATH_MAX);
    if (update_pwd(exe, buffer) == FAILURE)
        return (FAILURE);
    return (SUCCESS);
}

int check_cd_access(char buffer[PATH_MAX], char *old_pwd, cmd_t *cmd,
    exec_t *exe)
{
    if (access(cmd->cmd[1], F_OK | X_OK) == -1) {
        dprintf(2, "%s: %s.\n", cmd->cmd[1], strerror(errno));
        return (cmd_error(cmd, exe));
    }
    if (chdir(cmd->cmd[1]) == -1) {
        dprintf(2, "%s: %s.\n", cmd->cmd[1], strerror(errno));
        return (cmd_error(cmd, exe));
    }
    strcpy(old_pwd, buffer);
    getcwd(buffer, PATH_MAX);
    if (update_pwd(exe, buffer) == FAILURE)
        return (FAILURE);
    return (SUCCESS);
}

char cd(cmd_t *cmd, exec_t *exe)
{
    char buffer[PATH_MAX];
    static char old_pwd[PATH_MAX];

    getcwd(buffer, PATH_MAX);
    if (cmd->cmd[1] != NULL && strcmp(cmd->cmd[1], "-") == 0)
        return ((char)my_back_cd(buffer, old_pwd, cmd, exe));
    else if (cmd->cmd[1] != NULL && strcmp(cmd->cmd[1], "-") != 0)
        return ((char)check_cd_access(buffer, old_pwd, cmd, exe));
    if (cmd->cmd[1] == NULL)
        return ((char)move_to_home(buffer, old_pwd, cmd, exe));
    return (SUCCESS);
}

char m_cd(cmd_t *cmd, exec_t *exe)
{
    int i = m_arraylen((const char **)cmd->cmd);

    if (i <= 2)
        return (cd(cmd, exe));
    else {
        dprintf(2, "cd: Too many arguments.\n");
        return (cmd_error(cmd, exe));
    }
}