/*
** EPITECH PROJECT, 2019
** 42sh
** File description:
** Created by charles on 16/05/19.
*/

#ifndef PSU_42SH_2018_PARSING_H
#define PSU_42SH_2018_PARSING_H

#include "my_42sh.h"

int count_command(char **command);
int parse_line(cmd_t **command, char **line, exec_t *exec);
cmd_t *init_cmd_struct(int nb_cmd);
void *free_cmd_struct(cmd_t *command);
void check_parentheses_backsticks(char **command, int i, int *in_parentheses,
    int *in_backsticks);
int check_line(char **line);
int is_separators(char *word, int opt);
int is_redirection(char *word);
int is_null_forward(char **line, int i);
int check_separators(char **line, int count);
int check_redirection(char **line, int count);
int check_pths_bckstk(char **line);
int is_special_char(char *word, int opt);
int get_in_redirection(cmd_t **command, int count, char **line, int *i);
int get_out_redirection(cmd_t **command, int count, char **line, int *i);
int get_pipe(cmd_t **command, int count, char **line, int *i);
int get_semicolons(cmd_t **command, int count, char **line, int *i);
int get_cmd_line(cmd_t **command, int count, char **line, int *i);
int get_and(cmd_t **command, int count, char **line, int *i);
int get_or(cmd_t **command, int count, char **line, int *i);
char *find_env_value(exec_t *exe, char *name);
int is_null_cmd(cmd_t **command, int count, char **line, int *i);
int get_variable_name(char **word, cmd_t *command, exec_t *exec);
int replace_variable(cmd_t *command, exec_t *exec);
int get_parenthesis(cmd_t **command, int count, char **line, int *i);
int get_tilde(cmd_t *command, exec_t *exec);

#endif //PSU_42SH_2018_PARSING_H
