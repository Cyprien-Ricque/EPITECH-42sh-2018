##
## EPITECH PROJECT, 2018
## Makefile
## File description:
## Makefile
##

CC	=	gcc

I_DIR	=	-I include/ -I lib/my/include

CFLAGS	+=	$(I_DIR)
CFLAGS	+=	-W -Wall -Wextra

LDFLAGS	+=	$(LIB_MY)

LIB_MY	=	-L./lib/my -lmy

NAME	=	42sh

SRC	=	src/main.o	\
		src/input_and_parsing/parsing/initialization/init_cmd_parsing/init_cmd_parsing.o	\
		src/input_and_parsing/parsing/free/free_cmd_struct.o	\
		src/init_shell/init_shell.o	\
		src/input_and_parsing/line_edit/history_move.o	\
		src/shell_var_management/get_value.o	\
		src/execution/execution.o	\
		src/execution/next_com.o	\
		src/history/new_history.o	\
		src/execution/d_read.o	\
		src/execution/replace.o	\
		src/execution/pipe.o	\
		src/execution/prog.o	\
		src/execution/redirect.o	\
		src/execution/file.o	\
		src/organization/error_management.o	\
		src/organization/invalid.o	\
		src/organization/find_paths.o	\
		src/organization/signals_management.o	\
		src/input_and_parsing/parsing/free/free_array.o	\
		src/input_and_parsing/parsing/command_line_parsing/parse_line.o	\
		src/input_and_parsing/parsing/command_line_parsing/count_command.o	\
		src/input_and_parsing/line_edit/tab_character.o	\
		src/env_management/init_env.o	\
		src/alias/alias.o   \
		src/alias/error_handling_alias.o    \
		src/alias/manage_alias.o    \
		src/alias/send_new_value.o  \
		src/input_and_parsing/clean_cmd/clean_cmd.o	\
		src/input_and_parsing/clean_cmd/format.o	\
		src/shell_var_management/init_shell_vars.o	\
		src/input_and_parsing/line_edit/main_line_edit.o	\
		src/input_and_parsing/line_edit/escape_case.o	\
		src/input_and_parsing/line_edit/move_functions.o	\
		src/input_and_parsing/line_edit/disp_line.o	\
		src/input_and_parsing/line_edit/remove_char.o	\
		src/input_and_parsing/line_edit/setup_line_edit_settings.o	\
        src/input_and_parsing/line_edit/check_str_cut.o	\
        src/input_and_parsing/parsing/command_line_parsing/check_line/check_around.o	\
        src/input_and_parsing/parsing/command_line_parsing/check_line/check_line.o	\
        src/input_and_parsing/parsing/command_line_parsing/check_line/check_parentheses_backsticks.o	\
        src/input_and_parsing/parsing/command_line_parsing/check_line/check_redirection.o	\
        src/input_and_parsing/parsing/command_line_parsing/check_line/check_separators.o	\
        src/input_and_parsing/parsing/command_line_parsing/get_cmd_function/get_redirection.o	\
        src/input_and_parsing/parsing/command_line_parsing/get_cmd_function/get_separator.o	\
        src/input_and_parsing/parsing/command_line_parsing/get_cmd_function/get_cmd_line.o	\
        src/input_and_parsing/line_edit/prompt.o	\
        src/history/add_to_historic.o	\
        src/builtins/setenv.o \
        src/builtins/exit.o \
        src/builtins/echo.o \
        src/builtins/cd.o	\
        src/builtins/set.o	\
        src/builtins/unset.o	\
        src/builtins/link_for_chained_list.o	\
        src/builtins/set_status.o	\
        src/builtins/env.o	\
        src/builtins/cd_move_to_home.o  \
        src/builtins/which_and_where_alias.o  \
        src/builtins/builtins.o	\
        src/builtins/unsetenv.o	\
        src/builtins/where.o	\
        src/builtins/which.o	\
        src/builtins/history.o	\
        src/env_management/find_env_value.o \
        src/input_and_parsing/parsing/command_line_parsing/get_cmd_function/get_variable.o	\
        src/input_and_parsing/parsing/command_line_parsing/get_cmd_function/get_variable_name.o	\
	src/input_and_parsing/parsing/command_line_parsing/get_cmd_function/get_parenthesis.o	\
        src/input_and_parsing/parsing/command_line_parsing/get_cmd_function/get_tilde.o
all: $(NAME)

$(NAME):	$(SRC)
	make -C lib/my
	$(CC) -o $@ $^ $(LDFLAGS)

debug:	CFLAGS += -g
debug:	re

%.o: %.c
	$(CC) -o $@ -c $< $(CFLAGS)

clean:
	make clean -C  lib/my
	rm -f $(SRC)

fclean:		clean
	make fclean -C lib/my
	rm -f $(NAME)

re:		fclean all
