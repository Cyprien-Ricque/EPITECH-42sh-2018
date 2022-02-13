/*
** EPITECH PROJECT, 2018
** minishell_2
** File description:
** main
*/

#include "my.h"
#include "my_42sh.h"
#include <unistd.h>

char is_double_separator(char *str, int i)
{
    if (!str)
        return (FAILURE);
    if (str[i] == '>' && (str[i + 1] && str[i + 1] == '>') &&
        (i == 0 || str[i - 1] != '>'))
        return (SUCCESS);
    if (str[i] == '<' && (str[i + 1] && str[i + 1] == '<') &&
        (i == 0 || str[i - 1] != '<'))
        return (SUCCESS);
    if (str[i] == '&' && (str[i + 1] && str[i + 1] == '&') &&
        (i == 0 || str[i - 1] != '&'))
        return (SUCCESS);
    if (str[i] == '|' && (str[i + 1] && str[i + 1] == '|') &&
        (i == 0 || str[i - 1] != '|'))
        return (SUCCESS);
    return (FAILURE);
}

char is_simple_separator(char *str, int i)
{
    if (!str)
        return (FAILURE);
    if (str[i] == ';')
        return (SUCCESS);
    if (str[i] == '(' || str[i] == ')')
        return (SUCCESS);
    if (str[i] == '>' && (!str[i + 1] || str[i + 1] != '>') &&
        (i == 0 || str[i - 1] != '>'))
        return (SUCCESS);
    if (str[i] == '<' && (!str[i + 1] || str[i + 1] != '<') &&
        (i == 0 || str[i - 1] != '<'))
        return (SUCCESS);
    if (str[i] == '&' && (!str[i + 1] || str[i + 1] != '&') &&
        (i == 0 || str[i - 1] != '&'))
        return (SUCCESS);
    if (str[i] == '|' && (!str[i + 1] || str[i + 1] != '|') &&
        (i == 0 || str[i - 1] != '|'))
        return (SUCCESS);
    return (FAILURE);
}

char *find_no_space(char *str, int i)
{
    if (!str)
        return (NULL);
    if ((is_simple_separator(str, i) == SUCCESS ||
        is_double_separator(str, i) == SUCCESS) && i != 0 && str[i - 1] != ' ')
        str = m_scat(str, " ", i, 1);
    if (is_simple_separator(str, i) == SUCCESS && str[i + 1] &&
        str[i + 1] != ' ')
        str = m_scat(str, " ", i + 1, 1);
    if (is_double_separator(str, i) == SUCCESS && str[i + 2] &&
        str[i + 2] != ' ')
        str = m_scat(str, " ", i + 2, 1);
    return (str);
}

char *format(char *str)
{
    char *news = m_cleans(str, false);

    if (!news)
        return (NULL);
    if (m_slen(news) <= 1)
        return (news);
    for (int i = 0; news[i]; ++i) {
        if (news[i] == '\\' && news[i + 1])
            news[i + 1] = -news[i + 1];
        news = find_no_space(news, i);
        if (!news)
            return (NULL);
    }
    for (int i = 0; news[i]; ++i)
        if (news[i] < 0)
            news[i] *= -1;
    return (news);
}