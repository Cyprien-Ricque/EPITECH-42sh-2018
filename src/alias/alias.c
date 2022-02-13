/*
** EPITECH PROJECT, 2019
** ;
** File description:
** ;
*/

#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include "my_42sh.h"
#include "alias.h"
#include "my.h"

int size_tab_new(struc_s *ini)
{
    int check = 0;

    for (int i = 0; ini->new[i]; i++)
        check++;
    return (check);
}

int malloc_size_new(char **cmd, struc_s *ini)
{
    int check = 0;

    for (int i = 0; cmd[i]; i++) {
        if (i > 1)
            check++;
    }
    ini->new = malloc(sizeof(char *) * (check + 1));
    if (!ini->new)
        return (-1);
    return (check);
}

char get_both_arg(char **cmd, struc_s *ini)
{
    int check = 0;

    check = malloc_size_new(cmd, ini);
    if (check == -1)
        return (-1);
    for (int i = 0; i != check; i++) {
        ini->new[i] = strdup(cmd[i + 2]);
        if (!ini->new[i])
            return (-1);
    }
    ini->new[check] = NULL;
    ini->cmp = strdup(cmd[1]);
    if (!ini->cmp)
        return (-1);
    return (0);
}
