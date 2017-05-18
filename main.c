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

	ft_printf("\npush b :\n");
	tmp = (*lst)->data;
	intert_lst_front(lstb, new_lst_nbr(tmp));

	*lst = (*lst)->next;

	ft_printf("a is :\n");
	print_lst(*lst);

	ft_printf("\nb is :\n");
	print_lst(*lstb);
}

void	set_info(t_plst *lst, t_plst *lstb, t_pinfo *info)
{
	info->counta = count_nbr(lst);
	info->countb = count_nbr(lstb);
	info->lasta = get_last_data(lst);
	info->lastb = get_last_data(lstb);
}

void	three_bothsides(t_plst *lst, t_plst *lstb, int lasta, int lastb)
{
	if (lst->data > lst->next->data && lst->next->data > lasta && lstb->data < lstb->next->data && lstb->next->data < lastb)
	{
		ft_printf(GREE"rr\n"CLN);
		rotate_data(lst, lasta);
		rotate_data(lstb, lastb);
	}
	if (lst->data > lasta && lasta > lst->next->data && lstb->data < lastb && lastb < lstb->next->data)
	{
		ft_printf(GREE"rr\nss\n"CLN);
		rotate_n_swap(lst, lasta);
		rotate_n_swap(lst, lastb);
	}
	if (lst->next->data > lst->data && lst->data > lasta && lstb->next->data < lstb->data && lstb->data < lastb)
	{
		ft_printf(GREE"ss\nrr\n"CLN);
		swap_n_rotate(lst, lasta);
		swap_n_rotate(lstb, lastb);
	}
	if (lst->next->data > lasta && lasta > lst->data && lst->next->data < lastb  && lastb < lst->data)
	{
		ft_printf(GREE"ss\nrr\nss\n"CLN);
		swap_rotate_swap(lst, lasta);
		swap_rotate_swap(lstb, lastb);
	}
	if (lasta > lst->data && lst->data > lst->next->data && lastb < lst->data && lst->data < lst->next->data)
	{
		ft_printf(GREE"ss\n"CLN);
		swap_data(lst);
		swap_data(lstb);
	}
}

void	three_a_side(t_plst *lst, int last_data, char c)
{
	if (lst->data > lst->next->data && lst->next->data > last_data)//10 5 2
	{
		ft_printf(BLUE"r%c\n"CLN, c);
		rotate_data(lst, last_data);
	}
	if (lst->data > last_data  && last_data > lst->next->data)//10 2 5
	{
		ft_printf(BLUE"r%c\ns%c\n"CLN, c, c);
		rotate_n_swap(lst, last_data);
	}
	if (lst->next->data > lst->data && lst->data > last_data)//5 10 2
	{
		ft_printf(BLUE"s%c\nr%c\n"CLN, c, c);
		swap_n_rotate(lst, last_data);
	}
	if (lst->next->data > last_data && last_data > lst->data)//2 10 5..........
	{
		ft_printf(BLUE"s%c\nr%c\ns%c\n"CLN, c, c, c);
		swap_rotate_swap(lst, last_data);
	}
	if (last_data > lst->data && lst->data > lst->next->data)//5 2 10
	{
		ft_printf(BLUE"s%c\n"CLN, c);
		swap_data(lst);
	}
}

void	three_b_side(t_plst *lst, int last_data, char c)
{
	if (lst->data < lst->next->data && lst->next->data < last_data)//10 5 2
	{
		ft_printf(BLUE"r%c\n"CLN, c);
		rotate_data(lst, last_data);
	}
	if (lst->data < last_data  && last_data < lst->next->data)//10 2 5
	{
		ft_printf(BLUE"r%c\ns%c\n"CLN, c, c);
		rotate_n_swap(lst, last_data);
	}
	if (lst->next->data < lst->data && lst->data < last_data)//5 10 2
	{
		ft_printf(BLUE"s%c\nr%c\n"CLN, c, c);
		swap_n_rotate(lst, last_data);
	}
	if (lst->next->data < last_data && last_data < lst->data)//2 10 5..........
	{
		ft_printf(BLUE"s%c\nr%c\ns%c\n"CLN, c, c, c);
		swap_rotate_swap(lst, last_data);
	}
	if (last_data < lst->data && lst->data < lst->next->data)//5 2 10
	{
		ft_printf(BLUE"s%c\n"CLN, c);
		swap_data(lst);
	}
}

void	do_sort(t_plst **lst, t_plst **lstb, t_pinfo *info)
{
	int total;

	total = 0;
	total = count_nbr(*lst);

	ft_printf("original :\n");
	print_lst(*lst);

	while (total)
	{
		set_info(*lst, *lstb, info);
		ft_printf("count a is %d, count b is %d\n", info->counta, info->countb);
		ft_printf("last a is %d, last b is %d\n", info->lasta, info->lastb);
		if (info->counta >=3 && info->countb >= 3)
		{
			three_bothsides(*lst, *lstb, info->lasta, info->lastb);
			three_a_side(*lst, info->lasta, 'a');
			three_b_side(*lstb, info->lastb, 'b');
			push_b(lst, lstb);
		}
		else
		{
			if (info->counta >=3)
			{
				three_a_side(*lst, info->lasta, 'a');
				push_b(lst, lstb);
			}
			if (info->countb >= 3)
				three_b_side(*lstb, info->lastb, 'b');

		}
		total--;
	}
	// ft_printf("end :\n");
	// print_lst(lst);
	// print_lst(lstb);
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
	ft_printf("\nend a and b :\n");
	print_lst(lst);
	print_lst(lstb);
}




