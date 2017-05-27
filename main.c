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

int	main(int argc, char **argv)
{
	t_plst	*lst;
	t_plst	*lstb;
	t_pinfo	info;

	if (argc < 2)
	{
		ft_fprintf(2, "Arg Error\n");
		return (1);
	}
	lst = NULL;
	lstb = NULL;
	ft_memset(&info, 0, sizeof(t_pinfo));
	if (parse_arg(argc, argv, &lst, &info))
	{
		ft_fprintf(2, "Arg Error\n");
		return (1);
	}

	if (ft_strchr(info.flag, 'o'))
	{
		ft_printf(ft_strchr(info.flag, 'c') ? GREE"original stack: \n"CLN : "original stack: \n");
		// ft_printf("original stack: \n");
		ft_printf("\na is: \n");
		print_lst(lst);
		ft_printf("\nb is: \n");
		print_lst(lstb);
	}

	if (!(check_all_inorder(lst)))
		do_sort(&lst, &lstb, &info);

	if (ft_strchr(info.flag, 'n'))
	{
		ft_printf(ft_strchr(info.flag, 'c') ? GREE"\nthe end stack is: \n"CLN : "\nthe end stack is: \n");
		// ft_printf("\nthe end stack is: \n");
		ft_printf("\na is: \n");
		print_lst(lst);
		ft_printf("\nb is: \n");
		print_lst(lstb);
	}
	
	if (ft_strchr(info.flag, 's'))
		ft_printf(ft_strchr(info.flag, 'c') ? GREE"total: %d\n"CLN : "total: %d\n", info.steps);
		// ft_printf(GREE"total: %d\n"CLN, info.steps);
	deep_free(lst);
}
