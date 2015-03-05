# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lubaujar </var/mail/lubaujar>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2015/01/29 00:15:17 by lubaujar          #+#    #+#              #
#    Updated: 2015/03/06 00:06:20 by lubaujar         ###   ########.fr        #
#    Updated: 2015/02/20 07:58:23 by lubaujar         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a
RM = rm -rf
FLAGS = -Wall -Wextra -Werror
LDFLAGS = -I./include/ -I./libft/include/
SRC = \
	  convert.c convert2.c convert3.c\
	  utils.c utils2.c utils3.c\
	  is_infos.c search_infos.c search_infos2.c\
	  printf.c base.c\
	  add_width.c add_prec.c add_flag.c add_flag2.c\
	  wchar.c colors.c init.c\
	  OBJ = $(SRC:.c=.o)
	SRCDIR	= ./src/
	OBJDIR	= ./obj/
	INCDIR	= ./include/
	SRCS	= $(addprefix $(SRCDIR), $(SRC))
	OBJS	= $(addprefix $(OBJDIR), $(OBJ))
	INCS	= $(addprefix $(INCDIR), $(INC))

all: $(NAME)

$(NAME): $(OBJS) $(INCS)
	@gcc $(FLAGS) -o $@ $^ -L.libft/
	@ar rc $(NAME) $(OBJ)
	@ranlib $(NAME)
	@echo "\n\t \033[32m[All Fine's]\033[0m\n"

$(OBJS): $(SRCS)
	@gcc $(FLAGS) -c $(SRCS) $(LDFLAGS)
	@mkdir -p $(OBJDIR)
	@mv $(OBJ) $(OBJDIR)

clean:
	@echo "\nRM *.o.. \t      \033[32mOK BITCH!\033[0m"
	@$(RM) $(OBJS)
	@$(RM) *.o

fclean: clean
	@echo "RM libftprintf.a..    \033[32mOK BITCH!\033[0m"
	@$(RM) $(NAME)

re: fclean all

exec:
	@echo "\033[37mgcc *.c -I./includes/ ..\033[0m"
	@echo "  \033[37m..exec ./a.out\033[0m\n"
	@gcc *.c -g -I./includes/
	@echo "\033[31m./a.out\033[m\n"
	@./a.out

.PHONY: all clean fclean re exec
