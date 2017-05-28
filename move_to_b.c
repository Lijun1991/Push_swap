/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_to_b.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lwang <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/25 21:26:14 by lwang             #+#    #+#             */
/*   Updated: 2017/05/25 21:26:16 by lwang            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

static void	test_rotate(int nbr, t_pinfo *info, int count)
{
	int	tmp1;
	int	tmp2;

	tmp1 = 0;
	tmp2 = 0;
	if (nbr > info->diff_nbr)
		info->pos = info->diff_pos - 1;
	else
		info->pos = info->diff_pos;
	if (info->pos <= info->countb / 2 && count <= info->counta / 2)
		info->test_count = info->pos + count - \
	info->pos > count ? count : info->pos;
	else if (info->pos > info->countb / 2 && count > info->counta / 2)
	{
		tmp1 = info->counta - count;
		tmp2 = tmp1 > tmp2 ? tmp2 : tmp1;
		info->test_count = info->countb - info->pos + tmp1 - tmp2;
	}
	else if (info->pos <= info->countb / 2 && count > info->counta / 2)
		info->test_count = info->pos + info->counta - count;
	else if (info->pos > info->countb / 2 && count <= info->counta / 2)
		info->test_count = info->countb - info->pos + count;
}

static void	get_right_step(t_plst *lst, t_plst *lstb, t_pinfo *info, int *step)
{
	t_plst	*cur;
	int		count;

	count = 0;
	cur = lst;
	while (cur)
	{
		get_diff_location(cur->data, get_location(cur->data, lstb), lstb, info);
		info->counta = count_nbr(lst);
		info->countb = count_nbr(lstb);
		test_rotate(cur->data, info, count);
		(*step) = (*step) > info->test_count ? info->test_count : (*step);
		count++;
		cur = cur->next;
	}
}

int			get_right_nbr(t_plst *lst, t_plst *lstb, t_pinfo *info)
{
	int		count;
	int		step;
	t_plst	*cur1;

	step = 2147483647;
	count = 0;
	cur1 = lst;
	get_right_step(lst, lstb, info, &step);
	info->test_count = 0;
	while (cur1)
	{
		get_diff_location(cur1->data, \
			get_location(cur1->data, lstb), lstb, info);
		info->rotate_a = count;
		test_rotate(cur1->data, info, count);
		if (info->test_count == step)
			return (cur1->data);
		count++;
		cur1 = cur1->next;
	}
	return (0);
}

void		make_smallest_move_to_b(t_plst **lst, t_plst **lstb, t_pinfo *info)
{
	int	nbr;
	int	test;

	nbr = 0;
	test = 0;
	while (count_nbr(*lst))
	{
		nbr = get_right_nbr(*lst, *lstb, info);
		get_diff_location(nbr, get_location(nbr, *lstb), *lstb, info);
		info->countb = count_nbr(*lstb);
		if (nbr > info->diff_nbr)
			info->pos = info->diff_pos - 1;
		else
			info->pos = info->diff_pos;
		do_rotate_ab(info, lstb, lst);
		do_rotate_a(info, lst);
		do_rotate_b(info, lstb);
		info->steps = info->steps + 1;
		ft_printf("pb\n");
		push_b(lst, lstb);
		reset_info(info);
		print_bonus_v(info, *lst, *lstb);
	}
}
