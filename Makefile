# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: cbridget <cbridget@student.21-school.ru    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/01/05 19:40:05 by cbridget          #+#    #+#              #
#    Updated: 2022/01/28 13:57:55 by cbridget         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap

HEAD = hdrs/push_swap.h

#HEAD_B = hdrs/

SRC = push_swap.c wwargv.c

#SRC_B = push_swap_bonus.c

OBJ = $(addprefix obj/,$(SRC:.c=.o))

BUILD_FOLDER := $(shell mkdir -p obj)

FLAGS = -Wall -Werror -Wextra

CC = cc

.PHONY : all clean fclean bonus re LIB

all : LIB $(NAME)

LIB :
	@$(MAKE) bonus -C libft

$(NAME) : $(OBJ) libft/libft.a
	$(CC) $(FLAGS) $(OBJ) libft/libft.a -o $(NAME)

obj/%.o : src/%.c $(HEAD) Makefile
	$(CC) $(FLAGS) -I hdrs -I libft -c $< -o $@

#bonus :
#	$(LIB)
#	@make HEAD="$(HEAD_B)" SRC="$(SRC_B)"

clean :
	rm -rf obj
	$(MAKE) clean -C libft

fclean :
	rm -rf obj
	rm -f $(NAME)
	$(MAKE) fclean -C libft

re :
	rm -r obj/*.o
	rm -f $(NAME)
	$(MAKE) fclean -C libft
	$(MAKE)
