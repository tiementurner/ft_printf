# **************************************************************************** #
#                                                                              #
#                                                         ::::::::             #
#    Makefile                                           :+:    :+:             #
#                                                      +:+                     #
#    By: tblanker <tblanker@student.codam.nl>         +#+                      #
#                                                    +#+                       #
#    Created: 2019/11/27 16:05:25 by tblanker       #+#    #+#                 #
#    Updated: 2020/02/04 12:02:51 by tblanker      ########   odam.nl          #
#                                                                              #
# **************************************************************************** #

NAME	=	libftprintf.a

SRC		=	ft_printf.c flags.c print_out.c \
			get_format_strings.c get_unsigned_string.c \

LIBDIR	=	./helper/

LIBSRC	=	ft_strlen.c ft_isdigit.c ft_atoi.c arrayfill.c ft_itoa.c \
			ft_strdup.c ft_substr.c ft_strjoin.c ft_strchr.c\
			twenty_five_line_fixers.c dec_hex.c write_functions.c\

OFILES	=	$(SRC:.c=.o)
LIBOBJ	=	$(LIBSRC:.c=.o)
FLAGS	=	-Wall -Werror -Wextra

BLUE	= \x1b[34;01m
YELLOW	= \x1b[33;01m
GREEN	= \x1b[32;01m
RED		= \x1b[31;01m

all: $(NAME)

$(NAME): $(SRC) $(LIBSRC:%=$(LIBDIR)%)
	@echo "$(BLUE)Compiling $(OFILES)"
	@gcc -c $(SRC) $(LIBSRC:%=$(LIBDIR)%) $(FLAGS)
	@echo "$(YELLOW)\nLinking into libftprintf...\n"
	ar rc $(NAME) $(OFILES) $(LIBOBJ)
	@echo "$(GREEN)\nLibrary Ready!\n"

clean:
	rm -f $(OFILES) $(LIBOBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all
