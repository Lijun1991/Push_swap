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

void	print_lst(t_plst *lst)
{
	t_plst *cur;

	cur = lst;
	while (cur)
	{
		ft_printf("%d\n", cur->data);
		cur = cur->next;
	}
	ft_printf("\n");
}

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

static void	sort_way1b(t_plst **lst, t_pinfo *info)
{
	ft_printf("rb\n");
	ft_printf("sb\n");
	rotate(lst, 1);
	swap_data(*lst);
	info->steps = info->steps + 2;
}

static void	sort_way2b(t_plst **lst, t_pinfo *info)
{
	ft_printf("sb\n");
	ft_printf("rb\n");
	swap_data(*lst);
	rotate(lst, 1);
	info->steps = info->steps + 2;
}

void		do_sort_three_b(t_plst **lst, t_pinfo *info)
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

void		get_diff_location(int nbr, int diff, t_plst *lstb, t_pinfo *info)
{
	int pos;
	t_plst *cur;

	pos = 0;
	cur = lstb;
	info->countb = count_nbr(lstb);
	if (ft_abs(cur->data - nbr) == diff)
	{
		if (cur->data > nbr)
		{
			info->pos = 0;//pos == rotate_times== move_steps;
			info->for_rotate = 0;
			return ;
		}
	}
	while (cur)
	{
		if (ft_abs(cur->data - nbr) == diff)
		{
			ft_printf("pos is---is %d\n", pos);
			
			if (cur->data < nbr)
			{
				
				if (pos - 1 > info->countb / 2)
				{
					ft_printf("hah, pos - 1 is %d, info->countb / 2 is %d\n", pos - 1, info->countb / 2);
					info->if_top_part = 1;
					info->for_rotate = pos;
					return (pos - 1);
				}
				else
				{
					info->for_rotate = pos;
					return (info->countb - pos - 1);
				}
			}
			else
			{
				ft_printf("2pos is is is %d\n", pos);
				if (count > info->countb / 2)
				{
					ft_printf("h, count is %d, info->countb / 2 is %d\n", count, info->countb / 2);
					info->if_top_part = 1;
					info->for_rotate = count;
					return (count - 1);
				}
				else
				{
					info->for_rotate = count;
					return (info->countb - count - 1);
				}
			}
		}
		pos++;
		cur = cur->next;
	}
}

int		get_location(int nbr, t_plst *lstb, t_pinfo *info)
{
	int		tmp;
	int		diff;
	t_plst	*cur;

	cur = lstb;
	diff = cur->data - nbr;
	tmp = 0;
	while (cur)
	{
		tmp = ft_abs(cur->data - nbr);
		if (tmp < diff)
			diff = tmp;
		cur = cur->next;
	}
	ft_printf("diff is %d\n", diff);
	return (get_diff_location(nbr, diff, lstb, info));
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
	// int move;
	int	move1;
	// int move2;
	// int move3;

	// move = 0;
	move1 = 0;
	// move2 = 0;
	// move3 = 0;
	if (count_nbr(*lst) >= 3)
	{
		move1 = (*lst)->data;
		// move2 = (*lst)->next->data;
		// move3 = get_last_data(*lst);
		// ft_printf("last data is %d\n", move3);
		move1 = get_location(move1, *lstb, info);
		// move2 = get_location(move2, *lstb, info) + 1;
		// move3 = get_location(move3, *lstb, info) + 1;
		if (move1 == 0 || move2 == 1 || move3 == 1)
			ft_printf("something wrong\n");
		info->for_move_step = compare(move1, move2, move3);
		if (info->for_move_step == move1)
		{
			info->if_top_part = 0;
			info->for_rotate = 0;
			info->for_move_step = get_location((*lst)->data, *lstb, info);
			ft_printf("1if_top_part is %d, for_rotate is %d, info->for_move_step is %d\n", info->if_top_part, info->for_rotate, info->for_move_step);
			info->steps = info->steps + info->for_move_step + 1;
			while (info->for_move_step)
			{
				ft_printf("%s\n", info->if_top_part == 1 ? "rb" : "rrb");
				info->for_move_step--;
			}
			rotate(lstb, info->for_rotate);
			ft_printf("pb\n");
			push_b(lst, lstb);
		}
		else if (info->for_move_step == move2)
			ft_printf("2info->if_top_part is %d, info->for_rotate is %d, info->for_move_step is %d\n", info->if_top_part, info->for_rotate, info->for_move_step);
		else if (info->for_move_step == move3)
			ft_printf("3info->if_top_part is %d, info->for_rotate is %d, info->for_move_step is %d\n", info->if_top_part, info->for_rotate, info->for_move_step);
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



















