/*
** EPITECH PROJECT, 2019
** builtins.h
** File description:
** include for builtins
*/

#ifndef INC_BUILTINS_42SH_H
#define INC_BUILTINS_42SH_H

#include "my_42sh.h"

char m_setenv(cmd_t *cmd, exec_t *exe);
char m_env(cmd_t *cmd, exec_t *exe);
char m_unsetenv(cmd_t *cmd, exec_t *exe);
char m_echo(cmd_t *cmd, exec_t *exec UNUSED);
char m_exit(cmd_t *cmd, exec_t *exec);
char m_cd(cmd_t *command, exec_t *execn);
char *find_env_value(exec_t *exe, char *name);
char *find_shell_value(exec_t *exe, char *name);
list_t *find_env_node(exec_t *exe, char *name);
list_t *find_shell_node(exec_t *exe, char *name);
int move_to_home(char buffer[PATH_MAX], char *old_pwd, cmd_t *cmd,
    exec_t *exe);
char update_pwd(exec_t *exe, const char *pwd);
char m_set(cmd_t *cmd, exec_t *exe);
char m_unset(cmd_t *cmd, exec_t *exe);
int change_value(list_t *node, char *value);
char m_print_set(cmd_t *cmd UNUSED, exec_t *exe);
char set_error_management(cmd_t *cmd, exec_t *exe, const char *arg, bool *chg);
char *get_shell_var_name(const char *arg);
void set_node_ptr(list_t *exe, list_t *new_node);
char add_shell_node(list_t *exe, char *arg);
char create_shell_cl(exec_t *exe);
char change_shell_value(list_t *node, char *arg, bool *chg);
char link_two_shell_var(list_t *tmp, exec_t *exe, char *name,
    char *o_name);
char link_and_create(list_t **tmp, exec_t *exe);
char link_shell_var_with_env_var(list_t *tmp, exec_t *exe, char *v_name,
    char *env_name);
char create_shell_var_with_env_var(list_t *tmp, exec_t *exe, char *v_name,
    char *env_name);
char m_where(cmd_t *cmd, exec_t *exe);
void set_full_path_buffer(const char *cmd, char *const *path, char *buffer,
    int y);
char m_which(cmd_t *cmd, exec_t *exe);
char m_history(cmd_t *cmd, exec_t *exe);
int print_where_alias_ref(cmd_t *cmd, exec_t *exe, int y, bool *exist);
int print_which_alias_ref(cmd_t *cmd, exec_t *exe, int y, bool *exist);
char m_builtins(cmd_t *cmd, exec_t *exe);

char const *builtin[NB_BUILTINS];

#endif /*INC_BUILTINS_42SH_H*/