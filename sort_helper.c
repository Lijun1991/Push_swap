/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_helper.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lwang <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/19 17:45:05 by lwang             #+#    #+#             */
/*   Updated: 2017/05/19 17:45:07 by lwang            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

static int		find_second_small(t_plst *lst, int sa, t_pinfo *info)
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

/*
** check if the smallest number is in the middle of group a, we need to find  
** the second small nub to rotate and push before it, then swap b.
*/

int			check_at_middle(int count, t_plst *lst, t_pinfo *info)
{
	int		tmp;
	double	nbr;
	double	nbr1;

	nbr = (info->counta + 1) / 2;
	nbr1 = count + 1;
	tmp = info->sa;
	if (nbr1 == nbr)
	{
		ft_printf("hello\n");
		if (find_second_small(lst, tmp, info))
			count = get_location(lst, info->sa);
		info->at_middle = 1;
		return (count);
	}
	return (count);
}

int			get_times(t_plst *lst, t_pinfo *info)
{
	int	count;

	count = 0;
	count = get_location(lst, info->sa);
	if (info->at_middle)
		info->at_middle++;
	if ((int)info->counta > 3)
		count = check_at_middle(count, lst, info);
	info->sa_loc = count;
	if (count < (info->counta + 1) / 2)
	{
		info->top = 1;
		return (count);
	}
	return (info->counta - count);
}