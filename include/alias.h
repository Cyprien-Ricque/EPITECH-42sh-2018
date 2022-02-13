/*
** EPITECH PROJECT, 2018
** all_streuct.h
** File description:
** structure fonction
*/

#ifndef STRUCT_H_
#define STRUCT_H_

#include "my_42sh.h"

///error_handling_alias.c///
void print_liste(struc_s *ini);
char check_liste(struc_s *ini, char **cmd);
char error_handling_alias(char **cmd, struc_s *ini);

///alias.c///
int size_tab_new(struc_s *ini);
int malloc_size_new(char **cmd, struc_s *ini);
char get_both_arg(char **cmd, struc_s *ini);

///manage_alias.c///
int new_struc(char **cmd, struc_s *ini);
int add_to_first_struc(char **cmd, struc_s *ini);
int alias(char **cmd, struc_s *ini);
char m_alias(cmd_t *cmd, exec_t *exe);

///send_new_value.c///
char **loop_for_checking_alias(char **cmd, struc_s *ini);
char **check_if_need_change(char **array, struc_s *ini);
char **send_new_value(char **cmd, exec_t *exe);

#endif
