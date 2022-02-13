/*
** EPITECH PROJECT, 2019
** lib
** File description:
** Created by Emilien Delevoye
*/

#ifndef INC_42SH_LIB_H
#define INC_42SH_LIB_H

#define SUCCESS 0
#define FAILURE 84

int my_arraylen(char **array);
char **my_str_to_word_array(char *str, char separator);
char *get_next_line(int);
char **my_array_cat(char **array, char *str);
char **my_realloc_array(char **array);

#endif //INC_42SH_LIB_H
