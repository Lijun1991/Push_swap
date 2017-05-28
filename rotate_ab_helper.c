/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate_ab_helper.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lwang <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/27 21:27:49 by lwang             #+#    #+#             */
/*   Updated: 2017/05/27 21:27:51 by lwang            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

int			get_location(int nbr, t_plst *lstb)
{
	long	tmp;
	long	diff;
	t_plst	*cur;

	cur = lstb;
	diff = (long)ft_abs((long)cur->data - (long)nbr);
	tmp = 0;
	while (cur)
	{
		tmp = (long)ft_abs((long)cur->data - (long)nbr);
		if (tmp < diff)
			diff = tmp;
		cur = cur->next;
	}
	return (diff);
}

void		get_diff_location(int nbr, long diff, t_plst *lstb, t_pinfo *info)
{
	int		pos;
	t_plst	*cur;

	pos = 1;
	cur = lstb;
	info->countb = count_nbr(lstb);
	while (cur)
	{
		if (ft_abs((long)cur->data - (long)nbr) == diff)
		{
			info->diff_nbr = cur->data;
			info->diff_pos = pos;
			break ;
		}
		pos++;
		cur = cur->next;
	}
}

static void	rotate_ab_bottom(t_pinfo *info, t_plst **lstb, t_plst **lst)
{
	int	tmp1;
	int tmp2;
	int rrr_ab;

	tmp1 = 0;
	tmp2 = 0;
	rrr_ab = 0;
	if (info->rotate_a > count_nbr(*lst) / 2 \
		&& info->pos > count_nbr(*lstb) / 2)
	{
		info->sign_rrr = 1;
		tmp1 = count_nbr(*lst) - info->rotate_a;
		tmp2 = count_nbr(*lstb) - info->pos;
		rrr_ab = tmp1 > tmp2 ? tmp2 : tmp1;
		info->f_rotate_a = info->rotate_a + rrr_ab;
		info->f_pos = info->pos + rrr_ab;
		while (rrr_ab > 0)
		{
			ft_printf("rrr\n");
			info->steps = info->steps + 1;
			rrr_ab--;
		}
	}
}

void		do_rotate_ab(t_pinfo *info, t_plst **lstb, t_plst **lst)
{
	int rr_ab;

	rr_ab = 0;
	if (info->rotate_a <= count_nbr(*lst) / 2 \
		&& info->pos <= count_nbr(*lstb) / 2)
	{
		info->sign_rr = 1;
		rr_ab = info->pos > info->rotate_a ? info->rotate_a : info->pos;
		info->f_rotate_a = info->rotate_a - rr_ab;
		info->f_pos = info->pos - rr_ab;
		while (rr_ab > 0)
		{
			ft_printf("rr\n");
			info->steps = info->steps + 1;
			rr_ab--;
		}
	}
	rotate_ab_bottom(info, lstb, lst);
}
