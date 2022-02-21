/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbridget <cbridget@student-21school.ru>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/26 14:43:35 by cbridget          #+#    #+#             */
/*   Updated: 2022/02/21 12:12:16 by cbridget         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

struct s_stcks
{
	int				value;
	int				move;
	int				flag;
	struct s_stcks	*next;
	struct s_stcks	*back;
};

int				verify_argv(int argc, char **argv);
int				save_slist(int argc, char **argv, struct s_stcks **stck);
char			*save_slist01(int argc, char **argv);
char			*save_slist02(char **lines, int i);
int				check_nums(char **nums);
int				check_nums2(char **nums, int *i, int *j);
int				put_error(int err);
void			clear_nums(char **nums);
int				create_strct(char **nums, struct s_stcks **stck_a);
int				ft_atoi_s(const char *str, int *overflow);
int				skipp(const char *str, int *sign);
int				search_mmm(struct s_stcks *stck_a, int *mmm);
void			search_mmm2(int *array1, int *array2, int size, int *mmm);
int				length_stck(struct s_stcks *stck);
int				check_sort(struct s_stcks *stck);
struct s_stcks	*newlst(int value);
struct s_stcks	*addback(struct s_stcks *stck, int value);
struct s_stcks	*addtop(struct s_stcks *stck, int value);
struct s_stcks	*clean_stck(struct s_stcks *stck);
struct s_stcks	*push_ab(struct s_stcks **stck_1, struct s_stcks *stck_2,
					char mod, int act);
void			push_ab2(char mod, int act);
struct s_stcks	*rotate_ab(struct s_stcks *stck, char mod, int act);
int				rr(struct s_stcks **stck_a, struct s_stcks **stck_b, int act);
struct s_stcks	*rrotate_ab(struct s_stcks *stck, char mod, int act);
int				rrr(struct s_stcks **stck_a, struct s_stcks **stck_b, int act);
void			swap_ab(struct s_stcks *stck, int mod);
int				sort_stck(struct s_stcks **stck_a, int *mmm);
int				pushalltob(struct s_stcks **stck_a, struct s_stcks **stck_b,
					int *mmm);
int				pushalltob2(struct s_stcks **stck_a, struct s_stcks **stck_b,
					int *mmm, int size_a);
int				sort2(struct s_stcks **stck_a);
void			sort3(struct s_stcks **stck_a);
int				pushallback(struct s_stcks **stck_a, struct s_stcks **stck_b);
void			pushallback_logic(struct s_stcks **stck_a,
					struct s_stcks **stck_b, int *sizes);
int				findmin(struct s_stcks *stck, int *i);
int				findmin2(struct s_stcks *stck, int min, int *i);
int				findmin_last(struct s_stcks *stck, int *i);
int				findmin_last2(struct s_stcks *stck, struct s_stcks *tmp,
					int *j, int *i);
int				findmin_rrp(struct s_stcks *stck);
void			count_moves(struct s_stcks *stck_a, struct s_stcks *stck_b,
					int size_b, int size_a);
void			count_moves_logic(struct s_stcks *stck_b, int size_b, int i);
int				cma(struct s_stcks *stck_a, int val, int size_a, int *mvrr);
int				cma_logic(int i, int size_a);
int				rot_b(struct s_stcks **stck_b, int i, int size_b, int act);
int				rot_a(struct s_stcks **stck_a, struct s_stcks **stck_b,
					int size_a, int act);
int				rot_a2(struct s_stcks **stck_a, int size_a, int i, int act);
char			set_mod(int size, int *i);
int				rrightpositiona(struct s_stcks **stck_a, int act);
void			ft_radix(int *array1, int *array2, int size);
unsigned int	findbyte(unsigned int value, int nb);
void			full_sbytes(unsigned int *sbytes, int *array1, int i, int size);
void			last_pass(unsigned int *sbytes, int *array1, int *array2,
					int size);
int				cm_rr(int *mvdr);
int				double_rot(struct s_stcks **stck_b, struct s_stcks **stck_a,
					int pos, int act);
void			double_rot1(struct s_stcks **stck_a, struct s_stcks **stck_b,
					int *mvdr, int act);
void			double_rot2(struct s_stcks **stck_a, struct s_stcks **stck_b,
					int *mvdr, int act);
int				choose_find(struct s_stcks *stck_a, struct s_stcks *stck_b);
int				choose_find_01(struct s_stcks **new_stck_a,
					struct s_stcks **new_stck_b, struct s_stcks *stck_a,
					struct s_stcks *stck_b);
int				choose_find2(struct s_stcks **new_stck_a,
					struct s_stcks **new_stck_b, int *bs, int i);
struct s_stcks	*creat_ns(struct s_stcks *stck);

#endif
