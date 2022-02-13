/*
** EPITECH PROJECT, 2019
** my_puts_fd
** File description:
** my_puts_fd
*/

#include <unistd.h>
#include <string.h>
#include "lib.h"

void my_puts_fd(char const *str, int fd)
{
    if (str == NULL || fd < 0)
        return;
    write(fd, str, (size_t)strlen(str));
}