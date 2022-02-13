/*
** EPITECH PROJECT, 2018
** minishell_2
** File description:
** main
*/

#include "execution.h"
#include "my.h"
#include <unistd.h>

list_t *find_var(char *to_find, struct list_vars *head)
{
    if (!to_find || !head)
        return (NULL);
    for (list_t *tmp = head; tmp; tmp = tmp->next) {
        if (!m_scmp(to_find, tmp->names, 0))
            return (tmp);
    }
    return (NULL);
}