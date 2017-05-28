/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lwang <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/19 17:55:53 by lwang             #+#    #+#             */
/*   Updated: 2017/05/19 17:55:58 by lwang            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

int			find_biggist_nbr(t_plst *lstb)
{
	t_plst	*cur;
	int		ba;

	ba = lstb->data;
	if (lstb->next)
	{
		cur = lstb;
		while (cur)
		{
			if (cur->data > ba)
				ba = cur->data;
			cur = cur->next;
		}
	}
	return (ba);
}

void		rotate_b(t_plst **lstb, t_pinfo *info)
{
	int	pos;
	int	tmp;

	tmp = 0;
	pos = get_location_helper(*lstb, find_biggist_nbr(*lstb));
	if (pos <= count_nbr(*lstb) / 2)
	{
		rotate(lstb, pos);
		while (pos--)
		{
			ft_printf("rb\n");
			info->steps = info->steps + 1;
		}
	}
	else
	{
		tmp = count_nbr(*lstb) - pos;
		rotate(lstb, pos);
		while (tmp)
		{
			ft_printf("rrb\n");
			info->steps = info->steps + 1;
			tmp--;
		}
	}
}

void		push_three_to_b(t_plst **lst, t_plst **lstb, t_pinfo *info)
{
	int tmp;

	tmp = 3;
	while (tmp && *lst)
	{
		ft_printf("pb\n");
		push_b(lst, lstb);
		info->steps = info->steps + 1;
		tmp--;
	}
	do_sort_three_b(lstb, info);
}

void		move_back_to_a(t_plst **lst, t_plst **lstb, t_pinfo *info)
{
	int count;

	count = count_nbr(*lstb);
	while (count > 0)
	{
		ft_printf("pa\n");
		push_a(lst, lstb);
		info->steps = info->steps + 1;
		count--;
	}
}

void		do_sort(t_plst **lst, t_plst **lstb, t_pinfo *info)
{
	int total;

	total = 0;
	total = count_nbr(*lst);
	if (total > 5)
	{
		push_three_to_b(lst, lstb, info);
		make_smallest_move_to_b(lst, lstb, info);
		rotate_b(lstb, info);
		move_back_to_a(lst, lstb, info);
	}
	else if (total <= 5 && total > 3)
		do_sort_five(info, lst, lstb);
	else if (total == 3)
		do_sort_three(lst, info);
	else if (total == 2)
		sort_two_in_a(*lst, info);
}
