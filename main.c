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


void	push_b(t_plst **lst, t_plst **lstb)
{
	int tmp;

	ft_printf(PURPLE"pb\n"CLN);
	tmp = (*lst)->data;
	intert_lst_front(lstb, new_lst_nbr(tmp));

	*lst = (*lst)->next;

	// ft_printf("a is :\n");
	// print_lst(*lst);

	// ft_printf("\nb is :\n");
	// print_lst(*lstb);
}

void	push_a(t_plst **lst, t_plst **lstb)
{
	int		tmp;

	tmp = 0;
	ft_printf(YELLOW"pa\n"CLN);
	while (*lstb)
	{
		tmp = (*lstb)->data;
		intert_lst_front(lst, new_lst_nbr(tmp));
		*lstb = (*lstb)->next;
	}
}

int		get_smallest_a(t_plst *lst)
{
	t_plst *cur;
	int sa;

	sa = lst->data;
	if (lst)
	{
		cur = lst;
		while (cur)
		{
			if (cur->data < sa)
				sa = cur->data;
			cur = cur->next;
		}
	}
	return (sa);
}

/*
** check if the smallest number is in the middle of group a, we need to find  
** the second small nub to rotate and push before it, then swap b.
*/

// int		check_at_middle(int count, t_plst *lst, t_pinfo *info)
// {
// 	if (count = (info->counta + 1) / 2)
// 	{
// 		find_second_small(lst);

// 	}
// }

int		get_times(t_plst *lst, t_pinfo *info)
{
	t_plst *cur;
	int count;

	count = 0;
	if (lst)
	{
		cur = lst;
		while (cur)
		{
			if (cur->data == info->sa)
				break;
			count++;
			cur = cur->next;
		}
	}
	// check_at_middle(count, lst, info);
	info->sa_loc = count;
	if (count < (info->counta + 1) / 2)
	{
		info->top = 1;
		return (count);
	}
	return (info->counta - count);
}


void	get_location_sa(t_plst *lst, t_pinfo *info)
{
	info->counta = count_nbr(lst);
	info->sa = get_smallest_a(lst);
	info->times = get_times(lst, info);
}

void	do_sort(t_plst **lst, t_plst **lstb, t_pinfo *info)
{
	int total;

	(void)lstb;
	total = 0;
	total = count_nbr(*lst);

	ft_printf("original :\n\n");
	print_lst(*lst);
	info->steps = 0;
	while (total - 2)
	{
		info->top = 0;
		info->at_middle = 0;
		get_location_sa(*lst, info);
		ft_printf("count a is %d, count b is %d, sa is %d\n", info->counta, info->countb, info->sa);
		ft_printf("times a is %d, top %d, sa_loc is %d\n", info->times, info->top, info->sa_loc);
		info->steps = info->steps + info->times + 1;
		while (info->times)
		{
			ft_printf(GREE"%s\n"CLN, info->top == 1 ? "ra" : "rra");
			info->times--;
		}
		rotate(lst, info->sa_loc);
		push_b(lst, lstb);
		total--;
	}
	info->countb = count_nbr(*lstb);
	info->steps = info->steps + info->countb;
	if ((*lst)->data > (*lst)->next->data)
	{
		ft_printf(GREE"sa\n"CLN);
		swap_data(*lst);
		info->steps = info->steps + 1;
	}
	while (info->countb)
	{
		push_a(lst, lstb);
		info->countb--;
	}
}

int main(int argc, char **argv)
{
	t_plst *lst;
	t_plst *lstb;
	t_pinfo info;

	if (argc < 2)
		ft_fprintf(2, "argument err\n");
	lst = NULL;
	lstb = NULL;
	ft_memset(&info, 0, sizeof(t_pinfo));
	parse_arg(argv, &lst);
	do_sort(&lst, &lstb, &info);
	ft_printf(BLUE"end a is :\n"CLN);
	print_lst(lst);
	ft_printf(BLUE"end b is :\n"CLN);
	print_lst(lstb);
	ft_printf(RED"total steps %d\n"CLN, info.steps);
}




