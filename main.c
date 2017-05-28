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
		ft_fprintf(2, "Error\n");
		return (1);
	}
	lst = NULL;
	lstb = NULL;
	ft_memset(&info, 0, sizeof(t_pinfo));
	if (parse_arg(argc, argv, &lst, &info))
	{
		ft_fprintf(2, "Error\n");
		return (1);
	}
	print_bonus_o(&info, lst, lstb);
	if (!(check_all_inorder(lst)))
		do_sort(&lst, &lstb, &info);
	print_bonus_n(&info, lst, lstb);
	print_bonus_s(&info);
	deep_free(lst);
}
