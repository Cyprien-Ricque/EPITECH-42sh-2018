/*
** EPITECH PROJECT, 2018
** m_puts
** File description:
** m_puts
*/

#include <unistd.h>
#include <stddef.h>
#include "../../include/my.h"
#include <stdlib.h>
#include <stdio.h>

char check_flag(char **temp, char *str)
{
    if (!m_scmp(*temp, "str", 'r')) {
        if (str[1] == ' ' || str[1] == '\\')
            *temp += 3;
        return (SUCCESS);
    }
    if (!m_scmp(*temp, "nb", 'b') &&
        (m_cisnb(*str, RANDOM) == SUCCESS || *str == ' ')) {
        if (str[1] == ' ' || str[1] == '\\')
            *temp += 2;
        return (SUCCESS);
    }
    return (FAILURE);
}

char m_template(char *temp, char *str)
{
    for (int x = 0; str[x]; ++x) {
        if (str[x] == '-' && x > 0 && str[x - 1] >= '0' && str[x - 1] <= '9') {
            str = m_scat(str, "\\", x, 1);
            if (!str)
                return (FAILURE);
        }
    }
    for (int i = 0; str[i]; ++i) {
        if (check_flag(&temp, &(str[i])) == SUCCESS);
        else if (str[str[i] == '\\' ? ++i : i] == *temp &&
            m_scmp(temp, "str", 'r') && m_scmp(temp, "nb", 'b'))
            temp++;
        else
            return (FAILURE);
    }
    return (SUCCESS);
}