/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helper.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lwang <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/17 11:37:59 by lwang             #+#    #+#             */
/*   Updated: 2017/05/17 11:38:00 by lwang            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

int		count_nbr(t_plst *lst)
{
	t_plst	*cur;
	int		count;

	cur = lst;
	count = 0;
	while (cur)
	{
		cur = cur->next;
		count++;
	}
	return (count);
}

int		get_last_data(t_plst *lst)
{
	t_plst	*cur;

	if (lst)
	{
		cur = lst;
		while (cur && cur->next)
		{
			cur = cur->next;
		}
		return (cur->data);
	}
	return (0);
}

int		get_smallest_a(t_plst *lst)
{
	t_plst	*cur;
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

void	deep_free(t_plst *lst)
{
	t_plst	*tmp;

	while (lst)
	{
		tmp = lst->next;
		free(lst);
		lst = tmp;
	}
	free(lst);
}
