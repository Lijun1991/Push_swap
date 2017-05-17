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

// void	three_bothsides(t_plst *lst, t_plst *lstb, t_pinfo *info);

void	three_one_side(t_plst *lst, int last_data)
{
	if (lst->data > lst->next->data > last_data)
		rotate_data(lst, last_data);
	if (lst->data > last_data > lst->next->data)
		rotate_n_swap(lst, last_data);
	if (lst->next->data > lst->data > last_data)
		swap_n_rotate(lst, last_data);
	if (lst->next->data > last_data > lst->data)
		swap_rotate_swap(lst, last_data);
	if (last_data > lst->data > lst->next->data)
		swap_data(lst);
}

void	do_sort(t_plst *lst, t_plst *lstb, t_pinfo *info)
{
	int total;

	total = count_nbr(lst);

	ft_printf("original :\n");
	print_lst(lst);

	while (total - 3)
	{
		set_info(lst, lstb, info);
		ft_printf("count a is %d, count b is %d\n", info->counta, info->countb);
		ft_printf("last a is %d, last b is %d\n", last_data, info->lastb);
		if (counta >=3 && countb >= 3)
			three_bothsides(lst, lstb, info);
		else if (counta >=3 && countb < 3)
			three_one_side(lst, info->lasta);
		else if (counta < 3 && countb >= 3)
			three_one_side(lstb, info->latab);
		else if (counta < 3 && countb < 3)
			two_both_sides(lst, lstb, info);

		// if ((lst->next && lst->data > lst->next->data) && (lstb->next && lstb->data > lstb->next->data))
		// {
		// 	printf("SS, swap a and b/n");
		// 	swap_lst_data(lst);
		// 	swap_lst_data(lstb);
		// }
		// if (lst->next && lst->data > last_data)
		// 	rotate_lst_data(lst);
		push_b(&lst, &lstb);

		rotate_lst_data(lstb);
		swap_lst_data(lstb);
		total--;
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
	do_sort(lst, lstb, &info);
}




