# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: cbridget <cbridget@student-21school.ru>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/01/05 19:40:05 by cbridget          #+#    #+#              #
#    Updated: 2022/02/17 16:55:40 by cbridget         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap

HEAD = hdrs/push_swap.h

#HEAD_B = hdrs/

SRC = push_swap.c wwargv.c save_struct.c liblsts.c search_mmm.c ft_radix.c sort_stck.c\
operations.c operations2.c sort_stck2.c sort_stck3.c sort_double_r.c opt_sort.c\
sort_stck2_find.c sort_stck2_rot.c sort_stck2_01.c wwargv01.c

#SRC_B = push_swap_bonus.c

OBJ = $(addprefix obj/,$(SRC:.c=.o))

BUILD_FOLDER := $(shell mkdir -p obj)

FLAGS = -Wall -Werror -Wextra -g3

CC = cc

.PHONY : all clean fclean bonus re LIB

all : LIB $(NAME)

LIB :
	@$(MAKE) bonus -C libft

$(NAME) : $(OBJ) libft/libft.a
	$(CC) $(FLAGS) $(OBJ) -Llibft -lft -o $(NAME)

obj/%.o : src/%.c $(HEAD) Makefile
	$(CC) $(FLAGS) -iquote hdrs -iquote libft -c $< -o $@

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
