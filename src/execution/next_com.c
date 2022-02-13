/*
** EPITECH PROJECT, 2018
** minishell_2
** File description:
** pipe
*/

#include "execution.h"
#include "my.h"
#include <unistd.h>
#include <stdio.h>
#include "alias.h"

void skip_pipe(cmd_t *commands, exec_t UNUSED *execn, int *i)
{
    if (commands[*i].redir.out != PIPE)
        return;
    while (commands[*i].valid == true &&
        (commands[*i].redir.out == PIPE)) {
        ++(*i);
    }
}

bool next_com(cmd_t *commands, exec_t *execn, int *i)
{
    if (commands[*i].operator.in == false) {
        execn->chain = true;
        return (true);
    }
    if (execn->chain == false) {
        skip_pipe(commands, execn, i);
        return (false);
    }
    if ((commands[*i].operator.in == AND &&
        !m_getnb(get_value("?", execn->shell))) ||
        (commands[*i].operator.in == OR &&
            m_getnb(get_value("?", execn->shell))))
        execn->chain = true;
    else
        execn->chain = false;
    if (execn->chain == false)
        skip_pipe(commands, execn, i);
    return (execn->chain);
}