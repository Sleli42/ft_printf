# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lubaujar <lubaujar@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2015/01/07 22:00:53 by lubaujar          #+#    #+#              #
#    Updated: 2015/01/19 19:11:30 by lubaujar         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a
RM = rm -rf
SRC = convert.c\
	  func.c\
	  func2.c\
	  func3.c\
	  func4.c\
	  is_infos.c\
	  is_infos2.c\
	  printf.c\
	  search.c\
	  utils.c\
	  ft_itoa.c\
	  ft_atoi.c\
	  ft_strdup.c\
	  ft_strnew.c\
	  ft_putnbr.c\
	  ft_putchar.c\
	  ft_putstr.c\
	  ft_isdigit.c\
	  ft_strcpy.c\
	  ft_strlen.c\

OBJ = $(SRC:.c=.o)

all: $(NAME)

$(NAME):
	@gcc -c $(SRC)
	@ar rc $(NAME) $(OBJ)
	@ranlib $(NAME)

clean:
	$(RM) $(OBJ)

fclean: clean
	$(RM) $(NAME)

re: fclean all
