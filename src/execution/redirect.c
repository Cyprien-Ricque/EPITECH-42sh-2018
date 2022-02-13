/*
** EPITECH PROJECT, 2018
** minishell_2
** File description:
** redirect
*/

#include "execution.h"
#include "my.h"
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <string.h>
#include <errno.h>
#include <stdio.h>

int simple_write(cmd_t *command)
{
    int fd;

    fd = open(command->redir.out_name, O_WRONLY | O_CREAT | O_TRUNC, 0744);
    if (fd != -1) {
        dup2(fd, 1);
        close(fd);
    } else {
        fprintf(stderr, "%s: %s.\n", command->redir.out_name, strerror(errno));
        return (-1);
    }
    return (0);
}

int double_write(cmd_t *command)
{
    int fd;

    fd = open(command->redir.out_name, O_WRONLY | O_APPEND | O_CREAT, 0744);
    if (fd != -1) {
        dup2(fd, 1);
        close(fd);
    } else {
        fprintf(stderr, "%s: %s.\n", command->redir.out_name, strerror(errno));
        return (-1);
    }
    return (0);
}

int simple_read(cmd_t *command)
{
    int fd;

    fd = open(command->redir.in_name, O_RDONLY);
    fd = fd == -1 ? open(command->redir.in_name, O_RDONLY | O_DIRECTORY) : fd;
    if (fd != -1) {
        dup2(fd, 0);
        close(fd);
    } else {
        fprintf(stderr, "%s: %s.\n", command->redir.in_name, strerror(errno));
        return (-1);
    }
    return (0);
}

int dup_entries(cmd_t *command)
{
    int rv = 0;

    if (command->redir.in == DOUBLE)
        rv = double_read(command);
    if (command->redir.in == SIMPLE && rv != -1)
        rv = simple_read(command);
    if (command->redir.out == SIMPLE && rv != -1)
        rv = simple_write(command);
    if (command->redir.out == DOUBLE && rv != -1)
        rv = double_write(command);
    return (rv);
}