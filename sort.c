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

static void	test_rotate(int nbr, t_pinfo *info, t_plst *lstb)
{
	int tmp;

	tmp = 0;
	info->countb = count_nbr(lstb);
	ft_printf("info->diff_pos is %d, info->countb / 2 is %d\n", info->diff_pos, info->countb / 2);
	if (nbr > info->diff_nbr)
		info->pos = info->diff_pos - 1;
	else
		info->pos = info->diff_pos;
	if (info->pos <= info->countb / 2)
	{
		// rotate(lstb, info->pos);
		info->test_count = info->pos;
		// while (info->pos)
		// {
		// 	info->steps = info->steps + 1;
		// 	ft_printf("rb\n");
		// 	info->pos--;
		// }
	}
	else
	{
		tmp = info->countb - info->pos;
		// rotate(lstb, info->pos);
		info->test_count = tmp;
		// while (tmp)
		// {
		// 	info->steps = info->steps + 1;
		// 	ft_printf("rrb\n");
		// 	tmp--;	
		// }
	}
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

void		get_diff_location(int nbr, int diff, t_plst *lstb, t_pinfo *info)
{
	int pos;
	t_plst *cur;

	pos = 1;
	cur = lstb;
	info->countb = count_nbr(lstb);
	while (cur)
	{
		if (ft_abs(cur->data - nbr) == diff)
		{
			// ft_printf("pos is---is %d\n", pos);
			info->diff_nbr = cur->data;
			info->diff_pos = pos;
			break ;
		}
		pos++;
		cur = cur->next;
	}
}

int		get_location(int nbr, t_plst *lstb)
{
	int		tmp;
	int		diff;
	t_plst	*cur;

	cur = lstb;
	diff = ft_abs(cur->data - nbr);
	tmp = 0;
	while (cur)
	{
		tmp = ft_abs(cur->data - nbr);
		if (tmp < diff)
			diff = tmp;
		cur = cur->next;
	}
	ft_printf("smallest diff is %d\n", diff);
	return (diff);
}

int		get_right_nbr(t_plst *lst, t_plst *lstb, t_pinfo *info)
{
	int nbr1;
	int nbr2;
	int nbr3;
	int	steps1;
	int	steps2;
	int	steps3;
	int	step;

	step = 0;
	nbr1 = lst->data;
	nbr2 = lst->next->data;
	nbr3 = get_last_data(lst);

	get_diff_location(nbr1, get_location(nbr1, lstb), lstb, info);
	test_rotate(nbr1, info, lstb);
	steps1 = info->test_count;
	info->test_count = 0;

	get_diff_location(nbr2, get_location(nbr2, lstb), lstb, info);
	test_rotate(nbr2, info, lstb);
	steps2 = info->test_count + 1;
	info->test_count = 0;

	get_diff_location(nbr3, get_location(nbr3, lstb), lstb, info);
	test_rotate(nbr3, info, lstb);
	steps3 = info->test_count + 1;
	info->test_count = 0;

	ft_printf("steps1 is %d, steps2 is %d, steps3 is %d\n", steps1, steps2, steps3);
	step = compare(steps1, steps2, steps3);
	if (step == steps1)
		return (lst->data);
	else if (step == steps2)
		return (lst->next->data);
	else if (step == steps3)
		return (get_last_data(lst));
	return (0);
}


void	do_rotate(int nbr, t_pinfo *info, t_plst **lstb)
{
	int tmp;

	tmp = 0;
	info->countb = count_nbr(*lstb);
	ft_printf("info->diff_pos is %d, info->countb / 2 is %d\n", info->diff_pos, info->countb / 2);
	if (nbr > info->diff_nbr)
		info->pos = info->diff_pos - 1;
	else
		info->pos = info->diff_pos;
	if (info->pos <= info->countb / 2)
	{
		rotate(lstb, info->pos);
		while (info->pos)
		{
			info->steps = info->steps + 1;
			ft_printf("rb\n");
			info->pos--;
		}
	}
	else
	{
		tmp = info->countb - info->pos;
		rotate(lstb, info->pos);
		while (tmp)
		{
			info->steps = info->steps + 1;
			ft_printf("rrb\n");
			tmp--;	
		}
	}
}




void	make_smallest_move(t_plst **lst, t_plst **lstb, t_pinfo *info)
{
	int	nbr;
	t_plst *cur;
	int	tmp = 0;

	nbr = 0;
	cur = *lst;
	while (count_nbr(*lst))
	{
		if (count_nbr(*lst) >= 2)
		{
			nbr = get_right_nbr(*lst, *lstb, info);
			if (nbr == (*lst)->next->data)
			{
				ft_printf("ra\n");
				rotate(lst, 1);
				info->steps = info->steps + 1;
			}
			if (nbr == get_last_data(*lst))
			{
				ft_printf("rra\n");
				rotate(lst, count_nbr(*lst) - 1);
				info->steps = info->steps + 1;
			}
		}
		nbr = (*lst)->data;
		ft_printf("nbr is ---------------- %d, tmp is %d\n", nbr, tmp);
		get_diff_location(nbr, get_location(nbr, *lstb), *lstb, info);
		do_rotate(nbr, info, lstb);
		info->steps = info->steps + 1;
		ft_printf("pb\n");
		push_b(lst, lstb);

		ft_printf("\na is: \n");//
		print_lst(*lst);//
		ft_printf("\nb is: \n");//
		print_lst(*lstb);//

		tmp++;
	}
}

void		do_sort(t_plst **lst, t_plst **lstb, t_pinfo *info)
{
	int total;
	int	tmp;

	total = 0;
	tmp = 3;
	total = count_nbr(*lst);
	if (total > 3)
	{
		while (tmp)
		{
			info->steps = info->steps + 1;
			ft_printf("pb\n");
			push_b(lst, lstb);
			tmp--;
		}
		do_sort_three_b(lstb, info);
		make_smallest_move(lst, lstb, info);
	}
	if (total <= 3)
		do_sort_three(lst, info);
}



















