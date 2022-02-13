/*
** EPITECH PROJECT, 2019
** 42sh
** File description:
** 42sh
*/

#ifndef EXEC_42SH_42SH_H
#define EXEC_42SH_42SH_H

#include "my_42sh.h"

char execution(cmd_t *cmds, exec_t *exe);
char m_pipe(cmd_t *commands, exec_t *execn);
char signal_management(exec_t *execn, cmd_t *commands);
bool exec_errors(int status, bool first);
char init_execution(exec_t *exe);
char end_execution(exec_t *execn);
int dup_entries(cmd_t *command);
int double_read(cmd_t *command);
char exec(cmd_t *command, exec_t *execn);
char invalid_com(char *command);
char *invalid_rights(char *command);
int exit_error(char *str);
char builtins(cmd_t *command, exec_t *execn);
bool is_builtins(char *command);
char var_is_ok(const char *var, bool print);
char file_type(struct stat sb);
bool is_file(char *file, bool read, bool write);
char arg_number_is_ok(exec_t *exe, cmd_t *cmd, int min, int max);
list_t *find_var(char *to_find, struct list_vars *head);
char **find_paths(char **env);
char new_var(list_t *head, char *var, char *value);
char cmd_error(cmd_t *command, exec_t *execn);
char append_env_node(list_t *exe, char *env_line);
char *get_value(char *to_find, struct list_vars *head);
char *find(char *command, char **paths);
void rv_management(cmd_t *command, exec_t *execn, pid_t pid, int dup);
char malloc_error(cmd_t UNUSED *command, exec_t UNUSED *execn);
bool is_local(char *command);
char var_error(UNUSED cmd_t *command, exec_t UNUSED *execn);
void skip_pipe(cmd_t *commands, exec_t *execn, int *i);
bool next_com(cmd_t *commands, exec_t *execn, int *i);
void replace(cmd_t *command, int *tmp, int save);

#endif //INC_42SH_MY_42SH_H