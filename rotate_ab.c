/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate_ab.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lwang <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/27 21:27:39 by lwang             #+#    #+#             */
/*   Updated: 2017/05/27 21:27:41 by lwang            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

static void	rotate_a_bottom(t_pinfo *info, t_plst **lst)
{
	int	tmp;

	tmp = 0;
	if (info->sign_rrr)
		tmp = info->f_rotate_a ? (count_nbr(*lst) - info->f_rotate_a) \
	: (count_nbr(*lst) - info->rotate_a);
	else
		tmp = (count_nbr(*lst) - info->rotate_a);
	rotate(lst, info->rotate_a);
	while (tmp > 0)
	{
		info->steps = info->steps + 1;
		ft_printf("rra\n");
		tmp--;
	}
}

void		do_rotate_a(t_pinfo *info, t_plst **lst)
{
	int	tmp1;

	tmp1 = 0;
	if (info->rotate_a <= count_nbr(*lst) / 2)
	{
		rotate(lst, info->rotate_a);
		if (info->sign_rr)
			tmp1 = info->f_rotate_a ? info->f_rotate_a : 0;
		else
			tmp1 = info->rotate_a;
		while (tmp1 > 0)
		{
			info->steps = info->steps + 1;
			ft_printf("ra\n");
			tmp1--;
		}
	}
	else
		rotate_a_bottom(info, lst);
}

static void	rotate_b_bottom(t_pinfo *info, t_plst **lstb)
{
	int	tmp;

	tmp = 0;
	if (info->sign_rrr)
		tmp = info->f_pos ? (count_nbr(*lstb) - info->f_pos) \
	: (count_nbr(*lstb) - info->pos);
	else
		tmp = (count_nbr(*lstb) - info->pos);
	rotate(lstb, info->pos);
	while (tmp > 0)
	{
		info->steps = info->steps + 1;
		ft_printf("rrb\n");
		tmp--;
	}
}

void		do_rotate_b(t_pinfo *info, t_plst **lstb)
{
	int	tmp1;

	tmp1 = 0;
	if (info->pos <= info->countb / 2)
	{
		rotate(lstb, info->pos);
		if (info->sign_rr)
			tmp1 = info->f_pos ? info->f_pos : 0;
		else
			tmp1 = info->pos;
		while (tmp1 > 0)
		{
			info->steps = info->steps + 1;
			ft_printf("rb\n");
			tmp1--;
		}
	}
	else
		rotate_b_bottom(info, lstb);
}
