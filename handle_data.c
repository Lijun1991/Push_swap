/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_data.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lwang <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/17 11:36:49 by lwang             #+#    #+#             */
/*   Updated: 2017/05/17 11:36:51 by lwang            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

void	swap_data(t_plst *lst)
{
	int tmp;

	tmp = 0;
	// ft_printf("check swap[]");
	if (lst->next)//&& lst->data > lst->next->data
	{
		tmp = lst->data;
		lst->data = lst->next->data;
		lst->next->data = tmp;
		// ft_printf("swap top two : \n");
		print_lst(lst);
	}
	return ;
}

void	rotate_data(t_plst *lst, int last_data)
{
	int tmp;
	t_plst *cur;

	// ft_printf("check rotate[]");
	if (lst->next)//&& lst->data > last_data
	{
		tmp = lst->data;
		lst->data = last_data;
		cur = lst;
		while (cur->next)
			cur = cur->next;
		cur->data = tmp;
		// ft_printf("rotate first to last : \n");
		print_lst(lst);
	}
	return ; 
}

void	rotate_n_swap(t_plst *lst, int last_data)
{
	rotate_data(lst, last_data);
	swap_data(lst);
}

void	swap_n_rotate(t_plst *lst, int last_data)
{
	swap_data(lst);
	rotate_data(lst, last_data);
}

void	swap_rotate_swap(t_plst *lst, int last_data)
{
	swap_data(lst);
	rotate_data(lst, last_data);
	swap_data(lst);
}
