/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_lst.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lwang <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/17 11:36:39 by lwang             #+#    #+#             */
/*   Updated: 2017/05/17 11:36:41 by lwang            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

t_plst	*new_lst(char *s)
{
	t_plst *new;

	new = malloc(sizeof(t_plst));
	new->data = ft_atoi(s);
	new->next = NULL;
	return (new);
}

t_plst	*new_lst_nbr(int data)
{
	t_plst *new;

	new = malloc(sizeof(t_plst));
	new->data = data;
	new->next = NULL;
	return (new);
}

void	intert_lst_front(t_plst **lst, t_plst *new)
{
	new->next = *lst;
	*lst = new;
}

void	intert_lst_end(t_plst **lst, t_plst *new)
{
	t_plst *cur;

	cur = *lst;
	while (cur)
	{
		cur = cur->next;
	}
	*lst = new;
}

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
