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

void	count_nbr(t_plst *lst)
{
	t_plst *cur;
	int count;

	cur = lst;
	count = 0;
	while (cur)
		count++;
	return (count);
}

int		get_last_data(t_plst *lst)
{
	t_plst *cur;

	cur = lst;
	while (cur->next)
		cur = cur->next;
	return (cur->data);
}

