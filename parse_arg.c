/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_arg.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lwang <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/17 11:02:28 by lwang             #+#    #+#             */
/*   Updated: 2017/05/17 11:02:30 by lwang            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

int		check_all_inorder(t_plst *lst)
{
	t_plst	*cur;
	int 	tmp;
	int		len;

	cur = lst;
	tmp = 0;
	len = count_nbr(lst);
	while (cur->next)
	{	
		tmp = cur->next->data;
		if (tmp < cur->data)
			break;
		cur = cur->next;
		len--;
	}
	if (len == 1)
		return (1);
	return (0);
}

int		parse_arg(char **argv, t_plst **lst)
{
	int len;

	len = 0;
	if (check_arg(argv))
		return (1);
	while (argv[len])
		len++;
	while (len - 1)
	{
		intert_lst_front(lst, new_lst(argv[len - 1]));
		len--;
	}
	return (0);
}
