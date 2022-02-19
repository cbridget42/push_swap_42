# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: cbridget <cbridget@student-21school.ru>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/01/05 19:40:05 by cbridget          #+#    #+#              #
#    Updated: 2022/02/19 12:55:01 by cbridget         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap

NAME_B = checker

HEAD = hdrs/push_swap.h

HEAD_B = hdrs/checker_bonus.h

SRC = push_swap.c wwargv.c save_struct.c liblsts.c search_mmm.c ft_radix.c sort_stck.c\
operations.c operations2.c sort_stck2.c sort_stck3.c sort_double_r.c opt_sort.c\
sort_stck2_find.c sort_stck2_rot.c sort_stck2_01.c wwargv01.c

SRC_B = checker_bonus.c liblsts_bonus.c operations_bonus.c operations2_bonus.c\
wwargv_bonus.c wwargv01_bonus.c save_struct_bonus.c my_realloc_bonus.c

OBJ = $(addprefix obj/,$(SRC:.c=.o))

OBJ_B = $(addprefix obj/,$(SRC_B:.c=.o))

BUILD_FOLDER := $(shell mkdir -p obj)

FLAGS = -Wall -Werror -Wextra

CC = cc

.PHONY : all clean fclean bonus re LIB

all : LIB $(NAME)

LIB :
	$(MAKE) bonus -C libft

$(NAME) : $(OBJ)
	$(CC) $(FLAGS) $(OBJ) -Llibft -lft -o $(NAME)

$(NAME_B) : $(OBJ_B)
	$(CC) $(FLAGS) $(OBJ_B) -Llibft -lft -o $(NAME_B)

obj/%.o : src/%.c $(HEAD) Makefile libft/libft.a
	$(CC) $(FLAGS) -iquote hdrs -iquote libft -c $< -o $@

obj/%.o : src/bonus/%.c $(HEAD_B) Makefile libft/libft.a
	$(CC) $(FLAGS) -iquote hdrs -iquote libft -c $< -o $@

bonus : LIB $(NAME_B)

clean :
	rm -rf obj
	$(MAKE) clean -C libft

fclean :
	rm -rf obj
	rm -f $(NAME)
	rm -f $(NAME_B)
	$(MAKE) fclean -C libft

re :
	rm -r obj/*.o
	rm -f $(NAME)
	$(MAKE) fclean -C libft
	$(MAKE)
