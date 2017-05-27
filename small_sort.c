/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   small_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lwang <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/26 17:21:12 by lwang             #+#    #+#             */
/*   Updated: 2017/05/26 17:21:22 by lwang            ###   ########.fr       */
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
	if (lstb->next->data > lstb->data)
	{
		ft_printf("sa\n");
		swap_data(lstb);
		info->steps = info->steps + 1;
	}
}

void	do_sort_five(t_pinfo *info, t_plst **lst, t_plst **lstb)
{
	int total;

	total = count_nbr(*lst);
	while (total - 3)
	{
		info->top = 0;
		get_location_sa(*lst, info);
		info->steps = info->steps + info->times + 1;
		while (info->times--)
			ft_printf("%s\n", info->top == 1 ? "ra" : "rra");
		rotate(lst, info->sa_loc);
		ft_printf("pb\n");
		push_b(lst, lstb);
		total--;
	}
	do_sort_three(lst, info);
	sort_two_in_b(*lstb, info);
	total = count_nbr(*lstb);
	while (total--)
	{
		ft_printf("pa\n");
		info->steps = info->steps + 1;
		push_a(lst, lstb);
	}
}