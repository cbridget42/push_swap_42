/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbridget <cbridget@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/26 14:43:35 by cbridget          #+#    #+#             */
/*   Updated: 2022/01/28 13:56:14 by cbridget         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

int		save_slist(int argc,char **argv/*, &stk*/);
int		check_nums(char **nums, int *err);
int		put_error(int *err);
void	clear_nums(char **nums);

#endif
