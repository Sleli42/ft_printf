# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lubaujar <lubaujar@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2015/01/07 22:00:53 by lubaujar          #+#    #+#              #
#    Updated: 2015/01/07 22:03:23 by lubaujar         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = printf.a

RM = rm -f

SRC = convert.c\
	  convert_int_short.c\
	  flag_plus.c\
	  func.c\
	  is_infos.c\
	  is_infos2.c\
	  printf.c\
	  search.c\

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
