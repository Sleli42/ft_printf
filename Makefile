# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lubaujar </var/mail/lubaujar>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2015/01/29 00:15:17 by lubaujar          #+#    #+#              #
#    Updated: 2015/02/05 04:46:55 by lubaujar         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a
RM = rm -rf
SRC = convert.c\
	  convert2.c\
	  utils.c\
	  is_infos.c\
	  search_infos.c\
	  printf.c\
	  utils2.c\
	  utils3.c\
	  ft_atoi.c\
	  ft_itoa.c\
	  ft_uitoa.c\
	  ft_itoa_long.c\
	  ft_uitoa_long.c\
	  ft_putchar.c\
	  ft_putstr.c\
	  ft_strlen.c\
	  ft_isdigit.c\
	  ft_isalpha.c

OBJ = $(SRC:.c=.o)

INC = -I./includes/\

all: $(NAME)

$(NAME):
	@gcc $(INC) -c $(SRC)
	@ar rc $(NAME) $(OBJ)
	@ranlib $(NAME)

clean:
	$(RM) $(OBJ)

fclean: clean
	$(RM) $(NAME)

re: fclean all
