/*
** EPITECH PROJECT, 2019
** line_edit
** File description:
** Created by Emilien Delevoye
*/

#ifndef INC_42SH_LINE_EDIT_H
#define INC_42SH_LINE_EDIT_H

#include <termios.h>
#include <stdbool.h>
#include "my_42sh.h"

//Colors declaration
#define DEFAULT "\033[0m"
#define HIGHLIGHT "\033[1m"
#define UNDERLINE "\033[4m"
#define BLINK "\033[5m"
#define BLACK "\033[30m"
#define RED "\033[31m"
#define GREEN "\033[32m"
#define YELLOW "\033[33m"
#define BLUE "\033[34m"
#define PURPLE "\033[35m"
#define CYAN "\033[36m"
#define WHITE "\033[37m"

//Macros declaration

#define ESCAPE_KEY 0x001b
#define UP_KEY 0x0105
#define DOWN_KEY 0x0106
#define LEFT_KEY 0x0108
#define RIGHT_KEY 0x0107
#define LEFT_MOVE 1
#define RIGHT_MOVE 5
#define CTRL_LEFT -7
#define CTRL_RIGHT -8
#define CUT_AFTER 11
#define PASTE 25
#define CLEAR 12
#define MALLOC_INPUT 1
#define TAB_CHAR 9
//Structure declaration

typedef struct line_edit {
    unsigned int nb_char;
    unsigned int position;
    struct termios init;
    struct termios getc;
    struct termios geti;
    char *current_line;
    char *dup_current_line;
    list_history_t *head;
} line_edit_t;

//Functions declaration

char *take_entry(exec_t *);
int take_char(line_edit_t);
int escape_case(line_edit_t);
char disp_line(line_edit_t *, int, bool, line_t *);
void remove_char(line_edit_t *);
char move_right_left_back(line_edit_t *, int, exec_t *);
void default_move(line_edit_t *, int, bool *);
line_edit_t init_struct(exec_t *exec);
char check_str_cut(line_edit_t *, int, line_t *);
void prompt(exec_t *, bool);
char history_move(int, line_edit_t *);
char tab_character(line_edit_t *, exec_t *);

#endif //INC_42SH_LINE_EDIT_H
