/*
** EPITECH PROJECT, 2018
** GNL
** File description:
** GNL
*/

#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>
#include "get_next_line.h"
#include "lib.h"

char *put_in_output(char *buffer, char *output)
{
    int a = 0;
    int b = 0;
    int c = 0;

    for (; buffer[c] != '\0' && buffer[c] != '\n'; ++c);
    output = malloc(sizeof(char) * (c + 1));
    if (output == NULL)
        return (NULL);
    for (; buffer[a] != '\0' && buffer[a] != '\n'; ++a) {
        output[a] = buffer[a];
        output[a + 1] = '\0';
    }
    if (a == 0)
        output[0] = '\0';
    for (; buffer[a] != '\0'; ++b) {
        buffer[b] = buffer[a + 1];
        ++a;
    }
    buffer[b] = '\0';
    return (output);
}

char *my_realloc_and_replace(char *buffer, int len_buff)
{
    char *bottle = malloc(sizeof(char) * (len_buff + 1));
    static char status = 0;

    if (bottle == NULL)
        return (NULL);
    for (int a = 0; buffer[a] != '\0'; ++a)
        bottle[a] = buffer[a];
    bottle[len_buff] = '\0';
    if (status != 0)
        free(buffer);
    else
        status = 1;
    buffer = malloc(sizeof(char) * (len_buff + READ_SIZE + 2));
    if (buffer == NULL)
        return (NULL);
    for (int a = 0; bottle[a] != '\0'; ++a)
        buffer[a] = bottle[a];
    buffer[len_buff] = '\0';
    free(bottle);
    return (buffer);
}

char check_back_n(char const *tmp, char *buffer, int len_buff)
{
    short nb_n = 0;

    for (int a = 0; tmp[a] != '\0'; ++a) {
        buffer[len_buff] = tmp[a];
        ++len_buff;
        if (tmp[a] == '\n')
            ++nb_n;
    }
    buffer[len_buff] = '\0';
    if (nb_n != 0)
        return (TRUE);
    else
        return (FALSE);
}

static char *free_or_error(int fd, char *buffer)
{
    if (fd == -2 && buffer[0] != '\0')
        free(buffer);
    return (NULL);
}

char *get_next_line(int fd)
{
    static char *buffer = "\0";
    char tmp[READ_SIZE + 1];
    char *output = NULL;
    ssize_t len_read;
    int len_buff;
    char result;

    if (fd < 0)
        return (free_or_error(fd, buffer));
    while ((len_read = read(fd, tmp, READ_SIZE)) > 0 || buffer[0] != '\0') {
        tmp[len_read] = '\0';
        for (len_buff = 0; buffer[len_buff] != '\0'; ++len_buff);
        buffer = my_realloc_and_replace(buffer, len_buff);
        if (buffer == NULL)
            return (NULL);
        result = check_back_n(tmp, buffer, len_buff);
        if (result == TRUE || len_read < READ_SIZE)
            return (put_in_output(buffer, output));
    }
    return (output);
}