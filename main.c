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
	if (parse_arg(argv, &lst))
	{
		ft_fprintf(2, "Arg Error\n");
		return (1);
	}

	// ft_printf("original: \n");//
	// print_lst(lst);//

	if (!(check_all_inorder(lst)))
		do_sort(&lst, &lstb, &info);

	// ft_printf("\na is: \n");//
	// print_lst(lst);//
	// ft_printf("\nb is: \n");//
	// print_lst(lstb);//
	
	// ft_printf("steps is ............ is %d\n", info.steps);
	ft_printf(GREE"total steps is %d\n"CLN, info.steps);
	deep_free(lst);
}
