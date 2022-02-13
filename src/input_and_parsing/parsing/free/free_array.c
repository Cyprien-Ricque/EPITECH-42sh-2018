/*
** EPITECH PROJECT, 2019
** PSU_42sh_2018
** File description:
** Created by charles,
*/

#include <stdlib.h>

void free_array(char **array)
{
    for (int i = 0; array[i] != NULL; i++)
        free(array[i]);
    free(array);
}