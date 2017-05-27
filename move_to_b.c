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

int		get_location(int nbr, t_plst *lstb)
{
	int		tmp;
	int		diff;
	t_plst	*cur;

	cur = lstb;
	diff = ft_abs(cur->data - nbr);
	tmp = 0;
	while (cur)
	{
		tmp = ft_abs(cur->data - nbr);
		if (tmp < diff)
			diff = tmp;
		cur = cur->next;
	}
	// ft_printf("smallest diff is %d\n", diff);
	return (diff);
}

void		get_diff_location(int nbr, int diff, t_plst *lstb, t_pinfo *info)
{
	int pos;
	t_plst *cur;

	pos = 1;
	cur = lstb;
	info->countb = count_nbr(lstb);
	while (cur)
	{
		if (ft_abs(cur->data - nbr) == diff)
		{
			// ft_printf("pos is---is %d\n", pos);
			info->diff_nbr = cur->data;
			info->diff_pos = pos;
			break ;
		}
		pos++;
		cur = cur->next;
	}
}

static void	test_rotate(int nbr, t_pinfo *info, int count)
{
	int tmp;
	int tmp1;

	tmp = 0;
	tmp1 = 0;
	// ft_printf("info->diff_pos is %d, info->countb / 2 is %d\n", info->diff_pos, info->countb / 2);
	if (nbr > info->diff_nbr)
		info->pos = info->diff_pos - 1;
	else
		info->pos = info->diff_pos;

	if (info->pos <= info->countb / 2 && count <= info->counta / 2)
		info->test_count = info->pos + count;
	else if (info->pos > info->countb / 2 && count > info->counta / 2)
	{
		tmp = info->countb - info->pos;
		tmp1 = info->counta - count;
		info->test_count = tmp + tmp1;
	}
	else if (info->pos <= info->countb / 2 && count > info->counta / 2)
		info->test_count = info->pos + info->counta - count;
	else if (info->pos > info->countb / 2 && count <= info->counta / 2)
		info->test_count = info->countb - info->pos + count;
}

void	do_rotate_a(t_pinfo *info, t_plst **lst)
{
	int tmp;
	int tmp1;

	tmp = 0;
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
	{
		if (info->sign_rrr)
			tmp = info->f_rotate_a ? (count_nbr(*lst) - info->f_rotate_a) : (count_nbr(*lst) - info->rotate_a);
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
}

void	rotate_ab_at_bottom(t_pinfo *info, t_plst **lstb, t_plst **lst)
{
	int	tmp1;
	int tmp2;
	int rrr_ab;

	tmp1 = 0;
	tmp2 = 0;
	rrr_ab = 0;
	if (info->rotate_a > count_nbr(*lst) / 2 && info->pos > count_nbr(*lstb) / 2)
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

void	do_rotate_ab(t_pinfo *info, t_plst **lstb, t_plst **lst)
{
	int rr_ab;

	rr_ab = 0;
	// if (nbr > info->diff_nbr)
	// 	info->pos = info->diff_pos - 1;
	// else
	// 	info->pos = info->diff_pos;

	if (info->rotate_a <= count_nbr(*lst) / 2 && info->pos <= count_nbr(*lstb) / 2)
	{
		info->sign_rr = 1;
		rr_ab = info->pos > info->rotate_a ? info->rotate_a : info->pos;
		info->f_rotate_a = info->rotate_a - rr_ab;
		info->f_pos = info->pos - rr_ab;
		// ft_printf("info->pos is %d, info->f_pos is %d, count_nbr(*lstb) is %d\n", info->pos, info->f_pos, count_nbr(*lstb));
		// ft_printf("rr_ab is %d, info->f_rotate_a is %d, count_nbr(*lst) is %d\n", rr_ab, info->f_rotate_a, count_nbr(*lst));
		while (rr_ab > 0)
		{
			ft_printf("rr\n");
			info->steps = info->steps + 1;
			rr_ab--;
		}
	}
	rotate_ab_at_bottom(info, lstb, lst);
}


void	do_rotate(int nbr, t_pinfo *info, t_plst **lstb, t_plst **lst)
{
	int tmp;
	int	tmp1;
	int rr;
	int rrr;

	tmp = 0;
	tmp1 = 0;
	rr = 0;
	rrr = 0;
	info->countb = count_nbr(*lstb);
	
	if (nbr > info->diff_nbr)
		info->pos = info->diff_pos - 1;
	else
		info->pos = info->diff_pos;
	do_rotate_ab(info, lstb, lst);
	do_rotate_a(info, lst);

	// ft_printf("info->diff_pos is %d, info->countb / 2 is %d\n", info->diff_pos, info->countb / 2);
	// ft_printf("info->sign_ra is %d, info->sign_rra is %d\n", info->sign_ra, info->sign_rra);
	// ft_printf("info->pos is %d, info->f_pos is %d, count_nbr(*lstb) is %d\n", info->pos, info->f_pos, count_nbr(*lstb));
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
	{
		if (info->sign_rrr)
			tmp = info->f_pos ? (count_nbr(*lstb) - info->f_pos) : (count_nbr(*lstb) - info->pos);
		else
			tmp = (count_nbr(*lstb) - info->pos);
		// ft_printf("tmp is %d\n", tmp);
		rotate(lstb, info->pos);
		while (tmp > 0)
		{
			info->steps = info->steps + 1;
			ft_printf("rrb\n");
			tmp--;	
		}
	}
}

int		get_right_nbr(t_plst *lst, t_plst *lstb, t_pinfo *info)
{
	int count;
	int	step;
	t_plst *cur;
	t_plst *cur1;

	step = 2147483647;
	count = 0;

	cur = lst;
	cur1 = lst;
	while (cur)
	{
		get_diff_location(cur->data, get_location(cur->data, lstb), lstb, info);
		info->counta = count_nbr(lst);
		info->countb = count_nbr(lstb);
		test_rotate(cur->data, info, count);
		step = step > info->test_count ? info->test_count : step;
		// ft_printf("step is %d, count is %d, cur->data is %d\n", step, count, cur->data);
		count++;
		cur = cur->next;
	}
	info->test_count = 0;
	count = 0;
	while (cur1)
	{
		get_diff_location(cur1->data, get_location(cur1->data, lstb), lstb, info);
		info->rotate_a = count;
		// ft_printf("info->rotate_a is %d\n", info->rotate_a);
		test_rotate(cur1->data, info, count);
		if (info->test_count == step)
			return (cur1->data);
		count++;
		cur1 = cur1->next;
	}
	return (0);
}

void	make_smallest_move_to_b(t_plst **lst, t_plst **lstb, t_pinfo *info)
{
	int	nbr;
	int	test;


	nbr = 0;
	test = 0;
	while (count_nbr(*lst))
	{
		// if (count_nbr(*lst) >= 2)
		// {
		nbr = get_right_nbr(*lst, *lstb, info);
			// ft_printf("the nbr is %d\n", nbr);
		// }
		// else
		// 	nbr = (*lst)->data;
		// ft_printf("nbr is ---------------- %d, tmp is %d\n", nbr, tmp);
		get_diff_location(nbr, get_location(nbr, *lstb), *lstb, info);
		
		do_rotate(nbr, info, lstb, lst);
		info->steps = info->steps + 1;
		ft_printf("pb\n");
		push_b(lst, lstb);

		info->f_pos = 0;
		info->pos = 0;
		info->f_rotate_a = 0;
		info->rotate_a = 0;
		info->sign_rr = 0;
		info->sign_rrr = 0;

		if (ft_strchr(info->flag, 'v'))
		{
			ft_printf("\na is: \n");
			print_lst(*lst);
			ft_printf("\nb is: \n");
			print_lst(*lstb);
		}
	}
}
