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

	if (lst->next)
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
	int		sa;

	sa = lst->data;
	if (lst->next)
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

void	deep_free(t_plst *lst)
{
	t_plst	*tmp;

	while (lst)
	{
		tmp = lst->next;
		free(lst);
		lst = tmp;
	}
}

void	reset_info(t_pinfo *info)
{
	info->f_pos = 0;
	info->pos = 0;
	info->f_rotate_a = 0;
	info->rotate_a = 0;
	info->sign_rr = 0;
	info->sign_rrr = 0;
}
