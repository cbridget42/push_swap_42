/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_bonus.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbridget <cbridget@student-21school.ru>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/17 17:17:55 by cbridget          #+#    #+#             */
/*   Updated: 2022/02/19 12:25:38 by cbridget         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHECKER_BONUS_H
# define CHECKER_BONUS_H

struct s_stcks
{
	int				value;
	int				move;
	int				flag;
	struct s_stcks	*next;
	struct s_stcks	*back;
};

int				ft_exec(struct s_stcks **stck_a, struct s_stcks **stck_b);
int				ft_exec_read(char **cmd, unsigned int *size, int *i);
int				ft_exec2(struct s_stcks **stck_a, struct s_stcks **stck_b,
					char *cmd);
struct s_stcks	*clean_stck(struct s_stcks *stck);
int				check_sort(struct s_stcks *stck);
struct s_stcks	*newlst(int value);
struct s_stcks	*addback(struct s_stcks *stck, int value);
struct s_stcks	*addtop(struct s_stcks *stck, int value);
struct s_stcks	*push_ab(struct s_stcks **stck_1, struct s_stcks *stck_2,
					char mod, int act);
void			push_ab2(char mod, int act);
struct s_stcks	*rotate_ab(struct s_stcks *stck, char mod, int act);
int				rr(struct s_stcks **stck_a, struct s_stcks **stck_b, int act);
void			swap_ab(struct s_stcks *stck, int mod, int act);
struct s_stcks	*rrotate_ab(struct s_stcks *stck, char mod, int act);
int				rrr(struct s_stcks **stck_a, struct s_stcks **stck_b, int act);
void			ss(struct s_stcks *stck_a, struct s_stcks *stck_b, int mod);
int				save_slist(int argc, char **argv, struct s_stcks **stck_a);
int				check_nums(char **nums);
int				check_nums2(char **nums, int *i, int *j);
int				put_error(int err);
void			clear_nums(char **nums);
char			*save_slist01(int argc, char **argv);
char			*save_slist02(char **lines, int i);
int				length_stck(struct s_stcks *stck);
int				create_strct(char **nums, struct s_stcks **stck_a);
int				ft_atoi_s(const char *str, int *overflow);
int				skipp(const char *str, int *sign);
char			*my_realloc(char *result, unsigned int *size);
char			*my_realloc_two(char *result, unsigned int *size);

#endif
