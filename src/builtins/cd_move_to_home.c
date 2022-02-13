/*
** EPITECH PROJECT, 2018
** 42sh
** File description:
** cd_move_to_home
*/

#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <errno.h>
#include <string.h>
#include "execution.h"
#include "my.h"
#include "builtins.h"

int move_to_home(char buffer[PATH_MAX], char *old_pwd, cmd_t *cmd, exec_t *exe)
{
    char *home = find_env_value(exe, "HOME");

    if (home == NULL) {
        dprintf(2, "cd: No home directory.\n");
        return (cmd_error(cmd, exe));
    }
    if (chdir(home) == -1) {
        dprintf(2, "%s: %s.\n", home, strerror(errno));
        return (cmd_error(cmd, exe));
    }
    strcpy(old_pwd, buffer);
    getcwd(buffer, PATH_MAX);
    if (update_pwd(exe, buffer) == FAILURE)
        return (FAILURE);
    return (SUCCESS);
}