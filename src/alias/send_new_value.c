/*
** EPITECH PROJECT, 2018
** send_new_value
** File description:
** send_new_value
*/

#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include "my_42sh.h"
#include "alias.h"
#include "my.h"

char **replace_alias(struc_s *ini, int check, char **cmd)
{
    char **new_cmd = m_arraydup((const char **)ini->new);

    if (!new_cmd)
        return (NULL);
    for (int i = 1; cmd[i]; i++)
        new_cmd = m_arraycat(new_cmd, cmd[i], (check - 1) + i, -1);
    for (int i = 0; cmd[i]; i++)
        free(cmd[i]);
    free(cmd);
    return (new_cmd);
}

char **replace_new_val_alias(struc_s *ini, int size, char **cmd)
{
    int check = 0;

    for (int i = 1; cmd[i];i++)
        check++;
    if (size == 1) {
        free(cmd[0]);
        cmd[0] = strdup(ini->new[0]);
        if (!cmd[0])
            return (NULL);
        return (cmd);
    } else {
        return (replace_alias(ini, check, cmd));
    }
}

char **loop_for_checking_alias(char **cmd, struc_s *ini)
{
    int size = 0;

    if (strcmp(ini->cmp, cmd[0]) == 0) {
        size = size_tab_new(ini);
        cmd = replace_new_val_alias(ini, size, cmd);
        if (cmd == NULL)
            return (NULL);
    }
    return (cmd);
}

char **check_if_need_change(char **cmd, struc_s *ini)
{
    while (ini) {
        cmd = loop_for_checking_alias(cmd, ini);
        if (cmd == NULL)
            return (NULL);
        ini = ini->next;
    }
    return (cmd);
}

char **send_new_value(char **cmd, exec_t *exe)
{
    if (exe->ini->val == 1) {
        cmd = check_if_need_change(cmd, exe->ini);
        if (cmd == NULL)
            return (NULL);
    }
    return (cmd);
}
