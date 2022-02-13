/*
** EPITECH PROJECT, 2019
** 42sh
** File description:
** Created by Emilien Delevoye
*/

#include <stdlib.h>
#include <stdio.h>
#include "my_42sh.h"
#include "parsing.h"
#include "line_edit.h"
#include "my.h"

void prepare_string(char *str)
{
    bool chgmt = false;

    if (!str)
        return;
    for (int i = 0; str[i]; ++i) {
        if (str[i] == '\"' || str[i] == '\'') {
            chgmt = chgmt == false ? true : false;
            continue;
        }
        if (chgmt == true)
            str[i] = -str[i];
    }
}

void m_rm_ins(char *str, int e)
{
    if (!str)
        return;
    for (int i = e; str[i]; ++i)
        str[i] = str[i + 1];
}

void remove_quotes(char *cmd)
{
    if (!cmd)
        return;
    for (int i = 0; cmd[i]; ++i)
        if (cmd[i] == '\"' || cmd[i] == '\'')
            m_rm_ins(cmd, i);
}

char *clean_cmd(char *cmd)
{
    if (!cmd)
        return (NULL);
    prepare_string(cmd);
    cmd = m_cleans(cmd, false);
    cmd = format(cmd);
    prepare_string(cmd);
    remove_quotes(cmd);
    return (cmd);
}