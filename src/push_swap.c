/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbridget <cbridget@student-21school.ru>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/26 14:49:58 by cbridget          #+#    #+#             */
/*   Updated: 2022/02/13 13:55:58 by cbridget         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "push_swap.h"

int	main(int argc, char **argv)
{
	int				err;
	int				mmm[3];
	struct s_stcks	*stck_a;

	stck_a = (void *)0;
	err = save_slist(argc, argv, &stck_a);
	if (!err)
		err = search_mmm(stck_a, mmm);
	if (!err)
		err = sort_stck(&stck_a, mmm);
	clean_stck(stck_a);
	return (err);
}
