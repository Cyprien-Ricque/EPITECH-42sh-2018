/*
** EPITECH PROJECT, 2019
** 42sh
** File description:
** 42sh
*/

#ifndef INC_42SH_MY_42SH_H
#define INC_42SH_MY_42SH_H

#include "lib.h"
#include <stdbool.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <limits.h>

#define UNUSED __attribute__ ((unused))
#define SUCCESS 0
#define FAILURE 84
#define EXIT -1
#define PIPE 1
#define SIMPLE 2
#define DOUBLE 3
#define ERROR 1
#define AND 4
#define OR 5
#define NO_REF 127
#define ENV 1
#define SHELL 2
#define ENV_SHELL 3
#define NB_VAR_SHELL 8
#define NB_BUILTINS 14

//define for cd builtin
#define HOME 1
#define PWD 0

//define for find_env_value
#define EMPTY 0
#define NO_VALUE 127

typedef struct s_struc {
    int val;
    char *cmp;
    char **new;
    struct s_struc *next;
} struc_s;

typedef struct line_paperweight {
    char *paperweight;
} line_t;

typedef struct list_vars { //liste chainé des variables de l'tmp_env
    char *names;   // nom de la variables (elles peuvent avoir plusieurs noms)
    char *value;   // valeur de la viariable
    struct list_vars *next;
    struct list_vars *link;
} list_t;

typedef struct history_list {
    unsigned int position;
    char *content;
    struct history_list *next;
    struct history_list *prev;
} list_history_t;

typedef struct history {
    list_history_t *first;
    list_history_t *last;
    int fd;
} history_t;

typedef struct exec_needs {
    char **tmp_env;             //tmp_env*nam
    char **paths;        //paths dans l'tmp_env
    struc_s *ini;
    struct list_vars *env;
    struct list_vars *shell;
    char *r_values;
    long exit;
    bool to_exit;
    bool actual_exit;
    bool chain;
    int *pid;            //prog pid (-2 if prog doesn't need to be forked)
    line_t line;
    history_t history;
} exec_t;                //end is -1

typedef struct redirection {
    char in;        //dépend des define au dessus (ex: PIPE ou DOUBLE)
    char *in_name;  //nom du ficher de redirect si c'est SIMPLE OU DOUBLE
    char out;        // pareil mais pour output
    char *out_name;  //
} red_t;

typedef struct operators {
    char in;        //comme la struct d'au dessus mais avec AND et OR
    int in_r_value; //return value du prog lié avec celui par l'opérateur
    char out;
    int out_r_value;
} op_t;

typedef struct command {
    char **path;
    bool valid;         //fct valide ou pas
    char *bin;          //ls
    char **cmd;         //ls -la par exemple
    red_t redir;        //info sur les redirections (| > >> < <<)
    op_t operator;      //info sur les opérateurs (&& ||)
    char *sub_cmd;      //à changer
} cmd_t;

typedef struct summary {
    char r_value;
    exec_t *exe;
    cmd_t *command;
} sum_t;

void free_array(char **array);
char init_env(exec_t *exe, char **env);
char init_v_shell(exec_t *exe);
char init_shell(exec_t *exe, char **env);
char *clean_cmd(char *cmd);
char *format(char *str);

#endif //INC_42SH_MY_42SH_H