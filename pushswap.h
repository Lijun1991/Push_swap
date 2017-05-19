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
	int data;
	int group;
	struct s_plst *next;
}					t_plst;

typedef struct		s_pinfo
{
	int steps;
	double counta;
	int countb;
	// int lasta;
	// int lastb;
	int sa;
	// int tmp_sa;
	int at_middle;
	int sa_loc;
	int top;
	int times;
}					t_pinfo;

/*
** parse_arg.c
*/
void	parse_arg(char **argv, t_plst **lst);

/*
** handle_lst.c 
*/
void	print_lst(t_plst *lst);
void	intert_lst_front(t_plst **lst, t_plst *new);
void	intert_lst_end(t_plst **lst, t_plst *new);
t_plst	*new_lst_nbr(int data);
t_plst	*new_lst(char *s);

/*
** handle_data.c
*/
void	swap_data(t_plst *lst);
void	rotate(t_plst **lst, int n);
int		check_all_inorder(t_plst *lst);

/*
** helper.c
*/
void	get_location_sa(t_plst *lst, t_pinfo *info);
int		count_nbr(t_plst *lst);

#endif
