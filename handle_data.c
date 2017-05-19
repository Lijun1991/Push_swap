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