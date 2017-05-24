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

// void	get_location_sa(t_plst *lst, t_pinfo *info)
// {
// 	info->counta = count_nbr(lst);
// 	info->sa = get_smallest_a(lst);
// 	info->times = get_times(lst, info);
// }

void	swap_data(t_plst *lst)
{
	int	tmp;

	tmp = 0;
	if (lst && lst->next)
	{
		tmp = lst->data;
		lst->data = lst->next->data;
		lst->next->data = tmp;
	}
	return ;
}

void	rotate(t_plst **head, int n)
{
	int		count;
	t_plst	*current;
	t_plst	*nth_node;

	if (n == 0)
		return ;
	current = *head;
	count = 1;
	while (count < n && current != NULL)
	{
		current = current->next;
		count++;
	}
	if (current == NULL)
		return ;
	nth_node = current;
	while (current->next != NULL)
		current = current->next;
	current->next = *head;
	*head = nth_node->next;
	nth_node->next = NULL;
}

void	push_b(t_plst **lst, t_plst **lstb)
{
	t_plst	*tmp;

	tmp = NULL;
	if (*lst)
	{
		tmp = (*lst)->next != NULL ? (*lst)->next : NULL;
		intert_lst_front(lstb, new_lst_nbr((*lst)->data));
		free(*lst);
		*lst = NULL;
		*lst = tmp;
	}
}

void	push_a(t_plst **lst, t_plst **lstb)
{
	t_plst	*tmp;

	tmp = NULL;
	if (*lstb)
	{
		tmp = (*lstb)->next != NULL ? (*lstb)->next : NULL;
		intert_lst_front(lst, new_lst_nbr((*lstb)->data));
		free(*lstb);
		*lstb = NULL;
		*lstb = tmp;
	}
}
