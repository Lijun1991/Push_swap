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

void	do_sort_ten(t_pinfo *info, t_plst **lst, t_plst **lstb)
{
	int total;

	total = count_nbr(*lst);
	while (total)
	{
		info->top = 0;
		get_location_sa(*lst, info);
		info->steps = info->steps + info->times + 1;
		while (info->times)
		{
			ft_printf("%s\n", info->top == 1 ? "ra" : "rra");
			info->times--;
		}
		rotate(lst, info->sa_loc);
		ft_printf("pb\n");
		push_b(lst, lstb);
		if (info->at_middle == 2)
		{
			ft_printf("sb\n");
			swap_data(*lstb);
			info->at_middle = 0;
			info->steps = info->steps + 1;
		}
		total--;
	}
	total = 20;//........................................................
	while (total)
	{
		ft_printf("pa\n");
		push_a(lst, lstb);
		total--;
	}
}

// void		do_sort(t_plst **lst, t_plst **lstb, t_pinfo *info)
// {
// 	// int	total;

// 	// total = 0;
// 	// total = count_nbr(*lst);
// 	// info->steps = 0;
// 	// info->countb = 0;
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

// }

// int		get_up_data(t_plst *lstb, int	count)
// {
// 	t_plst *cur;

// 	cur = lstb;
// 	while (cur && count - 1 > 0)
// 	{
// 		count--;
// 		cur = cur->next;
// 	}
// 	ft_printf("up data is %d\n", cur->data);
// 	return (cur->data);
// }

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



int		get_last_mark(t_plst *lst)
{
	t_plst *cur;

	cur = lst;
	while (cur->next)
		cur = cur->next;
	return (cur->mark);
}


void	do_rotate_in_a(int nbr, t_pinfo *info, t_plst **lst)
{
	int tmp;

	tmp = 0;
	info->counta = count_nbr(*lst);
	// ft_printf("info->diff_pos is %d, info->counta / 2 is %d\n", info->diff_pos, info->counta / 2);
	if (nbr > info->diff_nbr)
		info->pos = info->diff_pos - 1;
	else
		info->pos = info->diff_pos;
	if (info->pos <= info->counta / 2)
	{
		rotate(lst, info->pos);
		while (info->pos)
		{
			info->steps = info->steps + 1;
			ft_printf("ra\n");
			info->pos--;
		}
	}
	else
	{
		tmp = info->counta - info->pos;
		rotate(lst, info->pos);
		while (tmp)
		{
			info->steps = info->steps + 1;
			ft_printf("rra\n");
			tmp--;	
		}
	}
}

int		find_biggist_nbr(t_plst *lstb)
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
	// ft_printf("biggist nbr in b s %d\n", ba);
	return (ba);
}

void	rotate_b(t_plst **lstb, t_pinfo *info)
{
	int pos;
	int tmp;

	tmp = 0;
	pos = get_location_helper(*lstb, find_biggist_nbr(*lstb));
	// ft_printf("biggist nbr in b pos is %d\n", pos);
	if (pos <= count_nbr(*lstb) / 2)
	{
		rotate(lstb, pos);
		while (pos)
		{
			ft_printf("rb\n");
			info->steps = info->steps + 1;
			pos--;
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
	// ft_printf("11steps is ............ is %d\n", info->steps);
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
	if (total > 10)
	{
		push_three_to_b(lst, lstb, info);
		make_smallest_move_to_b(lst, lstb, info);
		rotate_b(lstb, info);
		move_back_to_a(lst, lstb, info);
	}
	else if (total <= 10 && total > 3)
		do_sort_ten(info, lst, lstb);
	else if (total == 3)
		do_sort_three(lst, info);
	else if (total == 2)
		if ((*lst)->next->data < (*lst)->data)
		{
			ft_printf("sa\n");
			swap_data(*lst);
			info->steps = info->steps + 1;
		}
}
















