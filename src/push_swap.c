/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbridget <cbridget@student-21school.ru>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/26 14:49:58 by cbridget          #+#    #+#             */
/*   Updated: 2022/02/02 12:14:24 by cbridget         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "push_swap.h"

int	main(int argc, char **argv)
{
	int	err;
	int	mmm[3];
	struct s_stcks	*stck_a;

	stck_a =(void *)0;
	err = save_slist(argc, argv, &stck_a);
	if (!err)
		err = search_MMM(stck_a, mmm);
	printf("gdb error=%d\n", err);

	if (stck_a)
	{
		struct s_stcks *tmp = stck_a->next;
		printf ("%d ", stck_a->value);
		while (tmp && tmp != stck_a)
		{
			printf("%d ", tmp->value);
			tmp = tmp->next;
		}
	}
	printf("\n");

	clean_stck(stck_a);
//	read(0, &err, 1); this is for the tests
	return (err);
}
