/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbridget <cbridget@student-21school.ru>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/26 14:43:35 by cbridget          #+#    #+#             */
/*   Updated: 2022/02/02 12:07:36 by cbridget         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H


#include <stdio.h>

struct s_stcks
{
	int	value;
	int	move;
	struct s_stcks	*next;
	struct s_stcks	*back;
};

int		save_slist(int argc,char **argv, struct s_stcks **stck);
int		check_nums(char **nums);
int		put_error(int err);
void	clear_nums(char **nums);

void	ft_swap(int *array, int i, int j);
void	ft_qsort(int *array, int min, int max);

int	create_strct(char **nums, struct s_stcks **stck_a);
int	ft_atoiS(const char *str, int *overflow);
int	skipp(const char *str, int *sign);

int	search_MMM(struct s_stcks *stck_a, int *mmm);
int	length_stck(struct s_stcks *stck);
int	check_sort(int *A, int size);

struct s_stcks	*newlst(int value);
struct s_stcks	*addback(struct s_stcks *stck, int value);
struct s_stcks	*clean_stck(struct s_stcks *stck);

#endif
