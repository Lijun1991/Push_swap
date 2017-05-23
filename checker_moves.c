/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_moves.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lwang <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/20 23:24:00 by lwang             #+#    #+#             */
/*   Updated: 2017/05/20 23:24:03 by lwang            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

static void	ss_lst(t_plst **lst, t_plst **lstb)
{
	swap_data(*lst);
	swap_data(*lstb);
}

static void	rr_lst(t_plst **lst, t_plst **lstb)
{
	rotate(lst, 1);
	rotate(lstb, 1);
}

static void	rrr_lst(t_plst **lst, t_plst **lstb)
{
	rotate(lst, count_nbr(*lst) - 1);
	rotate(lstb, count_nbr(*lstb) - 1);
}

int			start_moves(char *line, t_plst **lst, t_plst **lstb)
{
	if (!ft_strcmp(line, "sa"))
		swap_data(*lst);
	else if (!ft_strcmp(line, "sb"))
		swap_data(*lstb);
	else if (!ft_strcmp(line, "ss"))
		ss_lst(lst, lstb);
	else if (!ft_strcmp(line, "pa"))
		push_a(lst, lstb);
	else if (!ft_strcmp(line, "pb"))
		push_b(lst, lstb);
	else if (!ft_strcmp(line, "ra"))
		rotate(lst, 1);
	else if (!ft_strcmp(line, "rb"))
		rotate(lstb, 1);
	else if (!ft_strcmp(line, "rr"))
		rr_lst(lst, lstb);
	else if (!ft_strcmp(line, "rra"))
		rotate(lst, count_nbr(*lst) - 1);
	else if (!ft_strcmp(line, "rrb"))
		rotate(lstb, count_nbr(*lstb) - 1);
	else if (!ft_strcmp(line, "rrr"))
		rrr_lst(lst, lstb);
	else
		return (1);
	return (0);
}
