/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbridget <cbridget@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/26 14:43:35 by cbridget          #+#    #+#             */
/*   Updated: 2022/01/30 17:08:24 by cbridget         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H


#include <stdio.h>

struct slist
{
	int	value;
	int	move;
	struct slist	*next;
	struct slist	*back;
};

int		save_slist(int argc,char **argv, struct slist **stck);
int		check_nums(char **nums);
int		put_error(int err);
void	clear_nums(char **nums);

int	create_strct(char **nums, struct slist **stckA);
int	ft_atoiS(const char *str, int *overflow);
int	skipp(const char *str, int *sign);

int	search_MMM(struct slist *stckA, int *mmm);
int	length_stck(struct slist *stck);
int	check_sort(int *A, int size);

struct slist	*newlst(int value);
struct slist	*addback(struct slist *stck, int value);
struct slist	*clean_stck(struct slist *stck);

#endif
