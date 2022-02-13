/*
** EPITECH PROJECT, 2019
** 42sh
** File description:
** Created by Emilien Delevoye
*/

#include <stdlib.h>
#include "my_42sh.h"
#include "parsing.h"
#include "line_edit.h"
#include "history.h"

char init_shell(exec_t *exe, char **env)
{
    if (init_env(exe, env) == FAILURE)
        return (FAILURE);
    if (init_v_shell(exe) == FAILURE)
        return (FAILURE);
    if (init_history(exe) == FAILURE)
        return (FAILURE);
    return (SUCCESS);
}