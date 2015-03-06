# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lubaujar </var/mail/lubaujar>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2015/01/29 00:15:17 by lubaujar          #+#    #+#              #
#    Updated: 2015/03/06 18:02:32 by lubaujar         ###   ########.fr        #
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
	  libft/src/ft_atoi.c libft/src/ft_isalpha.c libft/src/ft_isdigit.c\
	  libft/src/ft_itoa.c libft/src/ft_itoa_long.c libft/src/ft_putchar.c\
	  libft/src/ft_putstr.c libft/src/ft_strcmp.c libft/src/ft_strlen.c\
	  libft/src/ft_strrev.c libft/src/ft_uitoa.c libft/src/uitoa_long.c\
	  libft/src/wstrlen.c\

OBJ = $(SRC:.c=.o)
	SRCDIR	= ./src/
	OBJDIR	= ./obj/
	INCDIR	= ./include/
	LIBDIR  = ./libft/
	SRCS	= $(addprefix $(SRCDIR), $(SRC))
	OBJS	= $(addprefix $(OBJDIR), $(OBJ))
	INCS	= $(addprefix $(INCDIR), $(INC))

all: $(NAME)

$(NAME): $(OBJS) $(INCS)
	@echo "\n\t \033[32mIndexing lib ..\033[0m\n"
	@gcc $(FLAGS) -o $@ $^ -L./libft/
	@ar rc $(NAME) $(OBJS)
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
	@echo "RM libftprintf.a..\t      \033[32mOK BITCH!\033[0m"
	@$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re
