/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lwang <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/16 10:32:03 by lwang             #+#    #+#             */
/*   Updated: 2017/05/16 10:32:06 by lwang            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

int main(int argc, char **argv)
{
	t_plst *lst;
	t_plst *lstb;
	t_pinfo info;

	if (argc < 2)
	{
		ft_fprintf(2, "Arg Error\n");
		return (0);
	}
	lst = NULL;
	lstb = NULL;
	ft_memset(&info, 0, sizeof(t_pinfo));
	if (parse_arg(argv, &lst))
	{
		ft_fprintf(2, "Arg Error\n");
		return (1);
	}
	if (check_all_inorder(lst))
		return (0);
	do_sort(&lst, &lstb, &info);
	// ft_printf(BLUE"end a is :\n"CLN);
	// print_lst(lst);
	// ft_printf(BLUE"end b is :\n"CLN);
	// print_lst(lstb);
	// ft_printf(GREE"total steps %d\n"CLN, info.steps);
	deep_free(lst);
}
