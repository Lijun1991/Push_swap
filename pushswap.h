/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lwang <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/16 10:43:00 by lwang             #+#    #+#             */
/*   Updated: 2017/05/16 10:43:02 by lwang            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSHSWAP_H
# define PUSHSWAP_H

# include "libft.h"

typedef struct		s_plst
{
	int				data;
	int				group;
	struct s_plst	*next;
}					t_plst;

typedef struct		s_pinfo
{
	int		if_top_part;
	// int		if_top_part2;
	// int		if_top_part3;
	int		for_rotate;
	// int		for_rotate2;
	// int		for_rotate3;
	int		for_move_step;
	// int		for_move_step2;
	// int		for_move_step3;
	int		top_nbr;
	int		last_nbr;
	int		steps;
	double	counta;

	int		countb;
	int		sa;
	int		at_middle;
	int		sa_loc;
	int		top;
	int		times;
}					t_pinfo;

void				print_lst(t_plst *lst);


/*
** check_arg.c
*/
int					ck_is_nbr(char *s);
int					ck_is_int(char *s);
int					ck(int i, char *s, char **av);
int					ck_dup(char **argv);
int					check_arg(char **argv);

/*
** checker_moves.c
*/
int					start_moves(char *line, t_plst **lst, t_plst **lstb);

/*
** handle_data.c
*/
void				get_location_sa(t_plst *lst, t_pinfo *info);
void				swap_data(t_plst *lst);
void				rotate(t_plst **lst, int n);
void				push_b(t_plst **lst, t_plst **lstb);
void				push_a(t_plst **lst, t_plst **lstb);

/*
** handle_lst.c
*/
void				intert_lst_front(t_plst **lst, t_plst *new);
t_plst				*new_lst_nbr(int data);
t_plst				*new_lst(char *s);

/*
** helper.c
*/
int					count_nbr(t_plst *lst);
int					get_last_data(t_plst *lst);
int					get_smallest_a(t_plst *lst);
// int					get_location(t_plst *lst, int tmp_sa);
void				deep_free(t_plst *lst);

/*
** parse_arg.c
*/
int					check_all_inorder(t_plst *lst);
int					parse_arg(char **argv, t_plst **lst);

/*
** sort.c
*/
void				do_sort(t_plst **lst, t_plst **lstb, t_pinfo *info);
void				do_sort_three(t_plst **lst, t_pinfo *info);

/*
** sort_helper.c
*/
int					get_times(t_plst *lst, t_pinfo *info);
int					check_at_middle(int count, t_plst *lst, t_pinfo *info);

#endif
