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
	int counta;
	int countb;
	int lasta;
	int lastb;
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
t_plst	*new_lst_nbr(int data);
t_plst	*new_lst(char *s);

/*
** handle_data.c
*/
void	swap_data(t_plst *lst);
void	rotate_data(t_plst *lst, int last_data);
void	rotate_n_swap(t_plst *lst, int last_data);
void	swap_n_rotate(t_plst *lst, int last_data);
void	swap_rotate_swap(t_plst *lst, int last_data);

/*
** helper.c
*/
int		get_last_data(t_plst *lst);
int		count_nbr(t_plst *lst);

#endif
