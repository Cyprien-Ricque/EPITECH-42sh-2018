/*
** EPITECH PROJECT, 2018
** 42sh
** File description:
** file
*/

#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include "execution.h"
#include "my.h"

char file_type(struct stat sb)
{
    switch (sb.st_mode & S_IFMT) {
    case S_IFBLK:
        return ('b');
    case S_IFCHR:
        return ('c');
    case S_IFDIR:
        return ('d');
    case S_IFIFO:
        return ('p');
    case S_IFLNK:
        return ('l');
    case S_IFREG:
        return ('-');
    case S_IFSOCK:
        return ('s');
    default:
        return ('u');
    }
}

bool is_file(char *file, bool read, bool write)
{
    struct stat sb;
    int fd;

    if (stat(file, &sb) == -1 || file_type(sb) != '-')
        return (false);
    if (read == true && write == true) {
        fd = open(file, O_RDWR);
        if (fd != -1) {
            close(fd);
            return (true);
        }
        return (false);
    }
    fd = read == true ? open(file, O_RDONLY) : open(file, O_WRONLY);
    if (fd != -1 || (read == false && write == false)) {
        if (fd != -1)
            close(fd);
        return (true);
    }
    return (false);
}
