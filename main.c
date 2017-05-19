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
	free(*lst);
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
		free(*lstb);
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


int		find_second_small(t_plst *lst, int sa, t_pinfo *info)
{
	t_plst	*cur;
	int		tmp;

	tmp = lst->data;
	if (lst)
	{
		cur = lst;
		while (lst)
		{
			if (lst->data < tmp && lst->data != sa)
				tmp = lst->data;
			lst = lst->next;
		}
		info->sa = tmp;
		ft_printf("second sa is %d\n", info->sa);
		return (1);
	}
	return (0);
}

int		get_location(t_plst *lst, int tmp_sa)
{
	t_plst *cur;
	int count;

	count = 0;
	if (lst)
	{
		cur = lst;
		while (cur)
		{
			if (cur->data == tmp_sa)
				break;
			count++;
			cur = cur->next;
		}
	}
	return (count);
}

/*
** check if the smallest number is in the middle of group a, we need to find  
** the second small nub to rotate and push before it, then swap b.
*/

int		check_at_middle(int count, t_plst *lst, t_pinfo *info)
{
	int tmp;
	double nbr;
	double nbr1;

	nbr = (info->counta + 1) / 2;
	nbr1 = count + 1;
	tmp = info->sa;
	// printf("info->counta is %f, count is %d, nbr is %f\n, nbr1 is %f\n", info->counta, count, nbr, nbr1);
	if (nbr1 == nbr)
	{
		ft_printf("hello\n");
		if (find_second_small(lst, tmp, info))
			count = get_location(lst, info->sa);
		// ft_printf("info->sa is %d\n, first location is %d\n", info->sa, count);
		info->at_middle = 1;
		return (count);
	}
	return (count);
}

int		get_times(t_plst *lst, t_pinfo *info)
{
	int count;

	count = 0;
	count = get_location(lst, info->sa);
	// ft_printf("first location is %d\n", count);
	if (info->at_middle)
		info->at_middle++;
	if ((int)info->counta > 3)
		count = check_at_middle(count, lst, info);
	// ft_printf("seconde location is %d\n", count);
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

void	do_sort_three(t_plst **lst, t_pinfo *info)
{
	int	last_data;

	last_data = get_last_data(*lst);
	if ((*lst)->data > (*lst)->next->data && (*lst)->next->data > last_data)//10 5 2
	{
		ft_printf(GREE"ra\n"CLN);
		ft_printf(GREE"sa\n"CLN);
		rotate(lst, 1);
		swap_data(*lst);
		info->steps = info->steps + 2;
	}
	if ((*lst)->data > last_data  && last_data > (*lst)->next->data)//10 2 5
	{
		ft_printf(GREE"ra\n"CLN);
		rotate(lst, 1);
		info->steps = info->steps + 1;
	}
	if ((*lst)->next->data > (*lst)->data && (*lst)->data > last_data)//5 10 2
	{
		ft_printf(GREE"rra\n"CLN);
		rotate(lst, 2);
		info->steps = info->steps + 1;
	}
	if ((*lst)->next->data > last_data && last_data > (*lst)->data)//2 10 5
	{
		ft_printf(GREE"sa\n"CLN);
		ft_printf(GREE"ra\n"CLN);
		swap_data(*lst);
		rotate(lst, 1);
		info->steps = info->steps + 2;
	}
	if (last_data > (*lst)->data && (*lst)->data > (*lst)->next->data)//5 2 10
	{
		ft_printf(GREE"sa\n"CLN);
		swap_data(*lst);
		info->steps = info->steps + 1;
	}
}

void	do_sort(t_plst **lst, t_plst **lstb, t_pinfo *info)
{
	int total;

	(void)lstb;
	total = 0;
	total = count_nbr(*lst);

	// ft_printf("original :\n\n");
	// print_lst(*lst);
	info->steps = 0;
	info->countb =0;
	while (total - 3)
	{
		info->top = 0;
		get_location_sa(*lst, info);

		// ft_printf("count a is %f, count b is %d, sa is %d\n", info->counta, info->countb, info->sa);
		// ft_printf("times a is %d, top %d, sa_loc is %d\n", info->times, info->top, info->sa_loc);
		info->steps = info->steps + info->times + 1;
		while (info->times)
		{
			ft_printf(GREE"%s\n"CLN, info->top == 1 ? "ra" : "rra");
			info->times--;
		}
		rotate(lst, info->sa_loc);
		push_b(lst, lstb);
		if (info->at_middle == 2)
		{
			ft_printf(GREE"sb\n"CLN);
			swap_data(*lstb);
			info->at_middle = 0;
			info->steps = info->steps + 1;
		}
		total--;
	}
	if (total == 3)
		do_sort_three(lst, info);
	info->countb = count_nbr(*lstb);
	info->steps = info->steps + info->countb;
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
	{
		ft_fprintf(2, "argument err\n");
		return (0);
	}
	lst = NULL;
	lstb = NULL;
	ft_memset(&info, 0, sizeof(t_pinfo));
	parse_arg(argv, &lst);
	if (check_all_inorder(lst))
		return (0);
	do_sort(&lst, &lstb, &info);
	ft_printf(BLUE"end a is :\n"CLN);
	print_lst(lst);
	ft_printf(BLUE"end b is :\n"CLN);
	print_lst(lstb);
	ft_printf(GREE"total steps %d\n"CLN, info.steps);
	deep_free(lst);
}




