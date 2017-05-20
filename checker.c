/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lwang <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/19 12:21:02 by lwang             #+#    #+#             */
/*   Updated: 2017/05/19 12:21:14 by lwang            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

int		check_result(t_plst *lst, t_plst *lstb)
{
	if (check_all_inorder(lst) && !lstb)
		return (0);
	else
		return (1);
}

int		start_moves(char *line, t_plst **lst, t_plst **lstb)
{
	if (!ft_strcmp(line, "sa"))
		swap_data(*lst);
	else if (!ft_strcmp(line, "sb"))
		swap_data(*lstb);
	else if (!ft_strcmp(line, "ss"))
	{
		swap_data(*lst);
		swap_data(*lstb);
	}
	else if (!ft_strcmp(line, "pa"))
		push_a(lst, lstb);
	else if (!ft_strcmp(line, "pb"))
		push_b(lst, lstb);
	else if (!ft_strcmp(line, "ra"))
		rotate(lst, 1);
	else if (!ft_strcmp(line, "rb"))
		rotate(lstb, 1);
	else if (!ft_strcmp(line, "rr"))
	{
		rotate(lst, 1);
		rotate(lstb, 1);
	}
	else if (!ft_strcmp(line, "rra"))
		rotate(lst, count_nbr(*lst) - 1);
	else if (!ft_strcmp(line, "rra"))
		rotate(lstb, count_nbr(*lstb) - 1);
	else if (!ft_strcmp(line, "rrr"))
	{
		rotate(lst, count_nbr(*lst) - 1);
		rotate(lstb, count_nbr(*lstb) - 1);
	}
	else
	{
		ft_fprintf(2, "Error\n");
		return (1);
	}
	return (0);
}

int main(int argc, char **argv)
{
	t_plst *lst;
	t_plst *lstb;
	char *line;

	if (argc < 2)
		return (0);
	lst = NULL;
	lstb = NULL;
	if (parse_arg(argv, &lst))
	{
		ft_fprintf(2, "Arg Error\n");
		return (0);
	}
	while (get_next_line(0, &line))
	{
		if (start_moves(line, &lst, &lstb))
			return (0);
	}
	if (check_result(lst, lstb))
		ft_printf(RED"KO\n"CLN);
	else
		ft_printf(GREE"OK\n"CLN);
}









