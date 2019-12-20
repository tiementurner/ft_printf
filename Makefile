# **************************************************************************** #
#                                                                              #
#                                                         ::::::::             #
#    Makefile                                           :+:    :+:             #
#                                                      +:+                     #
#    By: tblanker <tblanker@student.codam.nl>         +#+                      #
#                                                    +#+                       #
#    Created: 2019/11/27 16:05:25 by tblanker       #+#    #+#                 #
#    Updated: 2019/12/19 16:50:27 by tblanker      ########   odam.nl          #
#                                                                              #
# **************************************************************************** #

NAME	=	libftprintf.a

SRC		=	ft_printf.c write_functions.c helper.c flags.c print_out.c \
			get_format_strings.c dec_hex.c get_unsigned_string.c

LIBDIR	=	./libft/

LIBSRC	=	ft_strlen.c ft_isdigit.c ft_atoi.c ft_bzero.c ft_itoa.c ft_strdup.c \
			ft_strjoin.c ft_substr.c

OFILES	=	$(SRC:.c=.o)
LIBOBJ	=	$(LIBSRC:.c=.o)
FLAGS	=	-Wall -Werror -Wextra

BLUE	= \x1b[34;01m
YELLOW	= \x1b[33;01m
GREEN	= \x1b[32;01m
RED		= \x1b[31;01m

all: $(NAME)

$(NAME): $(OFILES) $(LIBOBJ:%=$(LIBDIR)%)
	@echo "$(YELLOW)\nLinking into libftprintf...\n"
	ar rc $(NAME) $(OFILES) $(LIBOBJ:%=$(LIBDIR)%)
	@echo "$(GREEN)\nLibrary Ready!\n"

%.o: %.c
	@echo "$(BLUE)Compiling $<"
	@gcc -o $@ -c $< $(FLAGS)

clean:
	rm -f $(OFILES) $(LIBOBJ:%=$(LIBDIR)%)

exec: fclean $(NAME)
	gcc $(FLAGS) -L. -lftprintf test.c

fclean: clean
	rm -f $(NAME)

re: fclean all
