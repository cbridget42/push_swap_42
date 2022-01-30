/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbridget <cbridget@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/26 14:49:58 by cbridget          #+#    #+#             */
/*   Updated: 2022/01/30 17:09:40 by cbridget         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "push_swap.h"

int	main(int argc, char **argv)
{
	int	err;
	int	mmm[3];
	struct slist	*stckA;

	stckA =(void *)0;
	err = save_slist(argc, argv, &stckA);
	if (!err)
		err = search_MMM(stckA, mmm);
	printf("gdb error=%d\n", err);

	if (stckA)
	{
		struct slist *tmp = stckA->next;
		printf ("%d ", stckA->value);
		while (tmp && tmp != stckA)
		{
			printf("%d ", tmp->value);
			tmp = tmp->next;
		}
	}

	clean_stck(stckA);
//	read(0, &err, 1); this is for the tests
	return (err);
}
