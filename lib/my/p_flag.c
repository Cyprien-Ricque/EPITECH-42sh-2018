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

char *m_int(va_list ap, char *str, char *buf)
{
    int nb = va_arg(ap, int);
    int spaces = m_getnb(&(str[1]));

    for (int i = 0; i < spaces - m_slen(m_retbase(nb, 10)); ++i)
        buf = m_scat(buf, " ", m_slen(buf), 1);
    buf = m_scat(buf, m_retbase(nb, 10), m_slen(buf), 0);
    for (int i = 0; i > spaces + m_slen(m_retbase(nb, 10)); --i)
        buf = m_scat(buf, " ", m_slen(buf), 1);
    return (buf);
}

char *m_char(va_list ap, char *str, char *buf)
{
    char c = (char)va_arg(ap, int);
    int spaces = m_getnb(&(str[1]));

    for (int i = 0; i < spaces - 1; ++i)
        buf = m_scat(buf, " ", m_slen(buf), 1);
    buf = m_scat(buf, &c, m_slen(buf), 1);
    for (int i = 0; i > spaces + 1; --i)
        buf = m_scat(buf, " ", m_slen(buf), 1);
    return (buf);
}

char *m_string(va_list ap, char *str, char *buf)
{
    char *mstr = va_arg(ap, char * );
    int spaces = m_getnb(&(str[1]));

    if (!mstr)
        return (m_scat(buf, "(null)", m_slen(buf), 0));
    for (int i = 0; i < spaces - m_slen(mstr); ++i)
        buf = m_scat(buf, " ", m_slen(buf), 1);
    buf = m_scat(buf, mstr, m_slen(buf), 0);
    return (buf);
}

char *m_array(va_list ap, char *str, char *buf)
{
    char **array = va_arg(ap, char * *);
    int spaces = m_getnb(&(str[1]));

    if (!array || !array[0])
        return (buf);
    for (int i = 0; i < spaces - m_slen(array[0]); ++i)
        buf = m_scat(buf, " ", m_slen(buf), 1);
    buf = m_scat(buf, m_arrays(array, '\n'), m_slen(buf), 0);
    for (int i = 0;
        i > spaces + m_slen(array[m_arraylen((char const **)array) - 1]); --i)
        buf = m_scat(buf, " ", m_slen(buf), 1);
    return (buf);
}