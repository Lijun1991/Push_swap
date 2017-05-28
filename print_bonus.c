/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lwang <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/27 21:36:38 by lwang             #+#    #+#             */
/*   Updated: 2017/05/27 21:36:40 by lwang            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

void	print_bonus_o(t_pinfo *info, t_plst *lst, t_plst *lstb)
{
	if (ft_strchr(info->flag, 'o'))
	{
		ft_printf(ft_strchr(info->flag, 'c') \
			? GREE"original stack: \n"CLN : "original stack: \n");
		ft_printf(ft_strchr(info->flag, 'c') \
			? GREE"\na is: \n"CLN : "\na is: \n");
		print_lst(lst);
		ft_printf(ft_strchr(info->flag, 'c') \
			? GREE"\nb is: \n"CLN : "\nb is: \n");
		print_lst(lstb);
	}
}

void	print_bonus_n(t_pinfo *info, t_plst *lst, t_plst *lstb)
{
	if (ft_strchr(info->flag, 'n'))
	{
		ft_printf(ft_strchr(info->flag, 'c') \
			? GREE"\nthe end stack is: \n"CLN : "\nthe end stack is: \n");
		ft_printf("\na is: \n");
		print_lst(lst);
		ft_printf("\nb is: \n");
		print_lst(lstb);
	}
}

void	print_bonus_s(t_pinfo *info)
{
	if (ft_strchr(info->flag, 's'))
		ft_printf(ft_strchr(info->flag, 'c') \
			? GREE"total: %d\n"CLN : "total: %d\n", info->steps);
}

void	print_bonus_v(t_pinfo *info, t_plst *lst, t_plst *lstb)
{
	if (ft_strchr(info->flag, 'v'))
	{
		ft_printf(ft_strchr(info->flag, 'c') ? \
			GREE"\na is: \n"CLN : "\na is: \n");
		print_lst(lst);
		ft_printf(ft_strchr(info->flag, 'c') ? \
			GREE"\nb is: \n"CLN : "\nb is: \n");
		print_lst(lstb);
	}
}
