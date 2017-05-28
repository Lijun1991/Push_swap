/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_small_helper.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lwang <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/27 21:50:49 by lwang             #+#    #+#             */
/*   Updated: 2017/05/27 21:50:51 by lwang            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

void		sort_two_in_a(t_plst *lst, t_pinfo *info)
{
	if (lst->next->data < lst->data)
	{
		ft_printf("sa\n");
		swap_data(lst);
		info->steps = info->steps + 1;
	}
}

void		sort_two_in_b(t_plst *lstb, t_pinfo *info)
{
	if (lstb->next)
	{
		if (lstb->next->data > lstb->data)
		{
			ft_printf("sa\n");
			swap_data(lstb);
			info->steps = info->steps + 1;
		}
	}
}
