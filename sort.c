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

static void	sort_way1(t_plst **lst, t_pinfo *info)
{
	ft_printf("ra\n");
	ft_printf("sa\n");
	rotate(lst, 1);
	swap_data(*lst);
	info->steps = info->steps + 2;
}

static void	sort_way2(t_plst **lst, t_pinfo *info)
{
	ft_printf("sa\n");
	ft_printf("ra\n");
	swap_data(*lst);
	rotate(lst, 1);
	info->steps = info->steps + 2;
}

void		do_sort_three(t_plst **lst, t_pinfo *info)
{
	int	last_data;

	last_data = get_last_data(*lst);
	if ((*lst)->data > (*lst)->next->data && (*lst)->next->data > last_data)
		sort_way1(lst, info);
	if ((*lst)->data > last_data && last_data > (*lst)->next->data)
	{
		ft_printf("ra\n");
		rotate(lst, 1);
		info->steps = info->steps + 1;
	}
	if ((*lst)->next->data > (*lst)->data && (*lst)->data > last_data)
	{
		ft_printf("rra\n");
		rotate(lst, 2);
		info->steps = info->steps + 1;
	}
	if ((*lst)->next->data > last_data && last_data > (*lst)->data)
		sort_way2(lst, info);
	if (last_data > (*lst)->data && (*lst)->data > (*lst)->next->data)
	{
		ft_printf("sa\n");
		swap_data(*lst);
		info->steps = info->steps + 1;
	}
}

void		do_sort_three_b(t_plst **lst, t_pinfo *info)
{
	int	last_data;

	last_data = get_last_data(*lst);
	if ((*lst)->data < (*lst)->next->data && (*lst)->next->data < last_data)
		sort_way1(lst, info);
	if ((*lst)->data < last_data && last_data < (*lst)->next->data)
	{
		ft_printf("ra\n");
		rotate(lst, 1);
		info->steps = info->steps + 1;
	}
	if ((*lst)->next->data < (*lst)->data && (*lst)->data < last_data)
	{
		ft_printf("rra\n");
		rotate(lst, 2);
		info->steps = info->steps + 1;
	}
	if ((*lst)->next->data < last_data && last_data < (*lst)->data)
		sort_way2(lst, info);
	if (last_data < (*lst)->data && (*lst)->data < (*lst)->next->data)
	{
		ft_printf("sa\n");
		swap_data(*lst);
		info->steps = info->steps + 1;
	}
}

// static void	core_sort(int *total, t_pinfo *info, t_plst **lst, t_plst **lstb)
// {
// 	while (*total - 3 > 0)
// 	{
// 		info->top = 0;
// 		get_location_sa(*lst, info);
// 		info->steps = info->steps + info->times + 1;
// 		while (info->times)
// 		{
// 			ft_printf("%s\n", info->top == 1 ? "ra" : "rra");
// 			info->times--;
// 		}
// 		rotate(lst, info->sa_loc);
// 		ft_printf("pb\n");
// 		push_b(lst, lstb);
// 		// if (info->at_middle == 2)
// 		// {
// 		// 	ft_printf("sb\n");
// 		// 	swap_data(*lstb);
// 		// 	info->at_middle = 0;
// 		// 	info->steps = info->steps + 1;
// 		// }
// 		(*total)--;
// 	}
// }

// void		do_sort(t_plst **lst, t_plst **lstb, t_pinfo *info)
// {
// 	int	total;

// 	total = 0;
// 	total = count_nbr(*lst);
// 	info->steps = 0;
// 	info->countb = 0;
// 	core_sort(&total, info, lst, lstb);
// 	if (total == 3)
// 		do_sort_three(lst, info);
// 	if (total == 2)
// 		if ((*lst)->next->data < (*lst)->data)
// 		{
// 			ft_printf("sa\n");
// 			swap_data(*lst);
// 			info->steps = info->steps + 1;
// 		}
// 	info->countb = count_nbr(*lstb);
// 	info->steps = info->steps + info->countb;
// 	while (info->countb)
// 	{
// 		ft_printf("pa\n");
// 		push_a(lst, lstb);
// 		info->countb--;
// 	}
// }

int		get_up_data(t_plst *lstb, int	count)
{
	t_plst *cur;

	cur = lstb;
	while (cur && count - 1 > 0)
	{
		count--;
		cur = cur->next;
	}
	ft_printf("up data is %d\n", cur->data);
	return (cur->data);
}

int		get_diff_location(int nbr, int diff, t_plst *lstb)
{
	int count;
	t_plst *cur;

	count = 0;
	cur = lstb;
	info->countb = count_nbr(*lstb);
	while (cur)
	{
		if (ft_abs(cur->data - nbr) == diff)
		{
			if (get_up_data(lstb, count) - diff < cur->next->data - diff)
			{
				if (count - 1 >= countb / 2)
				{
					info->if_top_part1 = 1;
					return (count - 1);
				}
				else
					return (countb - count + 1);
			}
			else
				if (count >= countb / 2)
				{
					info->if_top_part1 = 1;
					return (count);
				}
				else
					return (countb - count);
		}
		count++;
		cur = cur->next;
	}
	return (0);
}

int		get_location(int nbr, t_plst *lstb)
{
	int		tmp;
	int		diff;
	t_plst	*cur;

	cur = lstb;
	diff = 0;
	tmp = 0;
	while (cur)
	{
		tmp = ft_abs(cur->data - nbr);
		if (tmp < diff)
			diff = tmp;
		cur = cur->next;
	}
	return (get_diff_location(nbr, diff, lstb));
}

int		compare(int move1, int move2, int move3)
{
	int tmp;

	tmp = move1;
	if (tmp > move2)
		tmp = move2;
	if (tmp > move3)
		tmp = move3;
	return (tmp);
}

void	make_smallest_move(t_plst **lst, t_plst **lstb, t_pinfo *info)
{
	int move;
	int	move1;
	int move2;
	int move3;

	move = 0;
	move1 = 0;
	move2 = 0;
	move3 = 0;
	if (count_nbr(*lst) >= 3)
	{
		move1 = (*lst)->data;
		move2 = (*lst)->next->data;
		move3 = get_last_data(*lst);
		move1 = get_location(move1, *lstb);
		move2 = get_location(move2, *lstb) + 1;
		move3 = get_location(move3, *lstb) + 1;
		if (move1 == 0 || move2 == 1 || move3 == 1)
			ft_printf("something wrong\n");
		move = compare(move1, move2, move3);
		if (move == move1)
			;
		else if (move == move2)
			;
		else if (move == move3)
			;
	}



}

void		do_sort(t_plst **lst, t_plst **lstb, t_pinfo *info)
{
	int total;

	total = 0;
	total = count_nbr(*lst);
	if (total > 3)
	{
		ft_printf("pb\n");
		push_b(lst, lstb);
		ft_printf("pb\n");
		push_b(lst, lstb);
		ft_printf("pb\n");
		push_b(lst, lstb);
		do_sort_three_b(lstb, info);
		make_smallest_move(lst, lstb, info);
	}
	if (total <= 3)
		do_sort_three(lst, info);
}



















