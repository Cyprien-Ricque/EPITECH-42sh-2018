/*
** EPITECH PROJECT, 2018
** my_printf
** File description:
** my_printf
*/

#include <stdarg.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include "lib.h"
#include "my.h"

char *m_iarray(va_list ap, char *str, char *buf)
{
    int *nbs = va_arg(ap, int * );
    int spaces = m_getnb(&(str[1]));

    if (!nbs)
        return (buf);
    for (int i = 0; i < spaces - m_slen(m_retbase(nbs[0], 10)); ++i)
        buf = m_scat(buf, " ", m_slen(buf), 1);
    for (int i = 0; nbs[i] != -1; ++i) {
        buf = m_scat(buf, m_retbase(nbs[i], 10), m_slen(buf), 0);
        if (nbs[i + 1] != -1)
            buf = m_scat(buf, " ", m_slen(buf), 1);
    }
    for (int i = 0; i > spaces + m_slen(m_retbase(nbs[0], 10)); --i)
        buf = m_scat(buf, " ", m_slen(buf), 1);
    return (buf);
}

char *m_maj_iarray(va_list ap, char *str, char *buf)
{
    int **nbs = va_arg(ap, int **);
    int spaces = (int)m_getnb(&(str[1]));

    if (!nbs || !nbs[0])
        return (buf);
    for (int i = 0; i < spaces - m_slen(m_retbase(nbs[0][0], 10)); ++i)
        buf = m_scat(buf, " ", m_slen(buf), 1);
    for (int j = 0; nbs[j]; ++j) {
        for (int i = 0; nbs[j][i] != -1; ++i) {
            buf = m_scat(buf, m_retbase(nbs[j][i], 10), m_slen(buf), 0);
            if (nbs[j][i + 1] != -1)
                buf = m_scat(buf, " ", m_slen(buf), 1);
        }
        if (nbs[j + 1])
            buf = m_scat(buf, "\n", m_slen(buf), 1);
    }
    for (int i = 0; i > spaces + m_slen(m_retbase(nbs[0][0], 10)); --i)
        buf = m_scat(buf, " ", m_slen(buf), 1);
    return (buf);
}

char *m_hex(va_list ap, char *str, char *buf)
{
    int nb = va_arg(ap, int);
    int spaces = m_getnb(&(str[1]));

    for (int i = 0; i < spaces - m_slen(m_retbase(nb, 16)); ++i)
        buf = m_scat(buf, "0", m_slen(buf), 1);
    buf = m_scat(buf, m_retbase(nb, 16), m_slen(buf), 0);
    for (int i = 0; i > spaces + m_slen(m_retbase(nb, 16)); --i)
        buf = m_scat(buf, " ", m_slen(buf), 1);
    return (buf);
}

char *maj(char *nb)
{
    for (int i = 0; nb && nb[i]; ++i)
        if (nb[i] >= 'a' && nb[i] <= 'f')
            nb[i] -= 'a' - 'A';
    return (nb);
}

char *m_maj_hex(va_list ap, char *str, char *buf)
{
    int nb = va_arg(ap, int);
    int spaces = m_getnb(&(str[1]));

    for (int i = 0; i < spaces - m_slen(m_retbase(nb, 16)); ++i)
        buf = m_scat(buf, "0", m_slen(buf), 1);
    buf = m_scat(buf, maj(m_retbase(nb, 16)), m_slen(buf), 0);
    for (int i = 0; i > spaces + m_slen(m_retbase(nb, 16)); --i)
        buf = m_scat(buf, " ", m_slen(buf), 1);
    return (buf);
}