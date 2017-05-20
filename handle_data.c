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
	if (lst->next)
	{
		tmp = lst->data;
		lst->data = lst->next->data;
		lst->next->data = tmp;
	}
	return ;
}

void	rotate(t_plst **head, int n)
{
	int count;
	t_plst *current;
	t_plst *nth_node;

	if (n == 0)
		return;
	current = *head;
	count = 1;
	while (count < n && current != NULL)
	{
		current = current->next;
		count++;
	}
	if (current == NULL)
		return;
	nth_node = current;
	while (current->next != NULL)
		current = current->next;
	current->next = *head;
	*head = nth_node->next;
	nth_node->next = NULL;
}

void	push_b(t_plst **lst, t_plst **lstb)
{
	int tmp;

	tmp = (*lst)->data;
	intert_lst_front(lstb, new_lst_nbr(tmp));
	free(*lst);
	*lst = (*lst)->next;
}

void	push_a(t_plst **lst, t_plst **lstb)
{
	int		tmp;

	tmp = 0;
	while (*lstb)
	{
		tmp = (*lstb)->data;
		intert_lst_front(lst, new_lst_nbr(tmp));
		free(*lstb);
		*lstb = (*lstb)->next;
	}
}
