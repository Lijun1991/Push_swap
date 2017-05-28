/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_small.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lwang <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/27 20:35:05 by lwang             #+#    #+#             */
/*   Updated: 2017/05/27 20:35:08 by lwang            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

void			do_sort_five(t_pinfo *info, t_plst **lst, t_plst **lstb)
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

static void		sort_way1b(t_plst **lst, t_pinfo *info)
{
	ft_printf("rb\n");
	ft_printf("sb\n");
	rotate(lst, 1);
	swap_data(*lst);
	info->steps = info->steps + 2;
}

static void		sort_way2b(t_plst **lst, t_pinfo *info)
{
	ft_printf("sb\n");
	ft_printf("rb\n");
	swap_data(*lst);
	rotate(lst, 1);
	info->steps = info->steps + 2;
}

void			do_sort_three_b(t_plst **lst, t_pinfo *info)
{
	int	last_data;

	last_data = get_last_data(*lst);
	if ((*lst)->data < (*lst)->next->data && (*lst)->next->data < last_data)
		sort_way1b(lst, info);
	if ((*lst)->data < last_data && last_data < (*lst)->next->data)
	{
		ft_printf("rb\n");
		rotate(lst, 1);
		info->steps = info->steps + 1;
	}
	if ((*lst)->next->data < (*lst)->data && (*lst)->data < last_data)
	{
		ft_printf("rrb\n");
		rotate(lst, 2);
		info->steps = info->steps + 1;
	}
	if ((*lst)->next->data < last_data && last_data < (*lst)->data)
		sort_way2b(lst, info);
	if (last_data < (*lst)->data && (*lst)->data < (*lst)->next->data)
	{
		ft_printf("sb\n");
		swap_data(*lst);
		info->steps = info->steps + 1;
	}
}
