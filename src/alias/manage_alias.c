/*
** EPITECH PROJECT, 2018
** manage_alias
** File description:
** manage_alias
*/

#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include "my_42sh.h"
#include "alias.h"
#include "my.h"

int new_struc(char **cmd, struc_s *ini)
{
    struc_s *ini2 = malloc(sizeof(struc_s));

    if (!ini2)
        return (84);
    if (get_both_arg(cmd, ini2) == -1)
        return (-1);
    while (ini->next != NULL)
        ini = ini->next;
    ini->next = ini2;
    ini2->next = NULL;
    return (0);
}

int add_to_first_struc(char **cmd, struc_s *ini)
{
    if (get_both_arg(cmd, ini) == -1)
        return (-1);
    ini->next = NULL;
    return (0);
}

int alias(char **cmd, struc_s *ini)
{
    static int place = 0;
    int check = 0;

    if (error_handling_alias(cmd, ini) == -1)
        return (-1);
    ini->val = 1;
    if (place == 0) {
        if (add_to_first_struc(cmd, ini) == -1)
            return (-1);
        place++;
    } else {
        check = check_liste(ini, cmd);
        if (check == 1 || check == -1)
            return (check);
        if (new_struc(cmd, ini) == -1)
            return (-1);
    }
    return (0);
}

char m_alias(cmd_t *cmd, exec_t *exe)
{
    if (strcmp(cmd->cmd[0], "alias") == 0) {
        if (alias(cmd->cmd, exe->ini) == -1)
            return (-1);
    } else {
        return (-1);
    }
    return (0);
}
