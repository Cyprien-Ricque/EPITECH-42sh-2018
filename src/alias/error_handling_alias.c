/*
** EPITECH PROJECT, 2018
** error_handling_alias
** File description:
** error_handling_alias
*/

#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include "my_42sh.h"
#include "alias.h"
#include "my.h"

void print_db_list(struc_s *ini)
{
    printf("%s\t(", ini->cmp);
    for (int i = 0; ini->new[i]; i++) {
        printf("%s", ini->new[i]);
        if (ini->new[i + 1] != NULL)
            printf(" ");
        else
            printf(")\n");
    }
}

void print_liste(struc_s *ini)
{
    while (ini) {
        if (ini->new[1] == NULL)
            printf("%s\t%s\n", ini->cmp, ini->new[0]);
        else
            print_db_list(ini);
        ini = ini->next;
    }
}

char replace_value_alias(struc_s *ini, char **cmd)
{
    if (strcmp(cmd[1], ini->cmp) == 0) {
        if (get_both_arg(cmd, ini) == -1)
            return (-1);
        return (1);
    }
    return (0);
}

char check_liste(struc_s *ini, char **cmd)
{
    int check = 0;

    while (ini) {
        check = replace_value_alias(ini, cmd);
        if (check == -1 || check == 1)
            return (check);
        ini = ini->next;
    }
    return (0);
}

char error_handling_alias(char **cmd, struc_s *ini)
{
    int i = 0;

    for (; cmd[i]; i++);
    if (i <= 2) {
        if (i == 1 && ini->val != 0)
            print_liste(ini);
        return (-1);
    } else {
        return (0);
    }
}
