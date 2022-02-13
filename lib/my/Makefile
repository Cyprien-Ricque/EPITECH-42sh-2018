##
## EPITECH PROJECT, 2018
## Makefile
## File description:
## Makefile
##

SRC	=	m_cisnb.o	\
		m_spelen.o	\
		gnl.o	\
		m_scpy.o	\
		get_next_line.o	\
		m_intuses.o	\
		m_realloc.o	\
		m_intarraylen.o	\
		m_realloc.o	\
		m_template.o	\
		m_arraydup.o	\
		m_arraycat.o	\
		m_getnb.o	\
		m_sarray.o	\
		m_scat.o	\
		m_sisnb.o	\
		m_arraylen.o	\
		m_cleans.o	\
		m_arrays.o	\
		m_puts.o	\
		m_retbase.o	\
		m_revs.o	\
		m_sdup.o	\
		m_slen.o	\
		cut.o	\
		m_sisnb.o	\
		m_scmp.o	\
		p_flag.o	\
		p_iflag.o	\
		m_printf.o	\
		my_puts_fd.o	\

CFLAGS	=	-W -Wall -Wextra -I ../../include -I include

NAME	=	libmy.a

all:	$(NAME)

$(NAME):	$(SRC)
	ar rc $(NAME) $^

%.o: %.c
	$(CC) -o $@ -c $< $(CFLAGS)

clean:
	rm -f $(SRC)

fclean:	clean
	rm -f $(NAME)

re:	fclean all
