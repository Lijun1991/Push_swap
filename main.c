/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lwang <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/16 10:32:03 by lwang             #+#    #+#             */
/*   Updated: 2017/05/16 10:32:06 by lwang            ###   ########.fr       */
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

void	print_lst(t_plst *lst)
{
	t_plst *cur;

	cur = lst;
	while (cur)
	{
		ft_printf("%d\n", cur->data);
		cur = cur->next;
	}
}

void	swap_lst_data(t_plst *lst)
{
	int tmp;

	tmp = 0;
	ft_printf("check swap[]");
	if (lst->next && lst->data > lst->next->data)
	{
		tmp = lst->data;
		lst->data = lst->next->data;
		lst->next->data = tmp;
		ft_printf("swap top two : \n");
		print_lst(lst);
	}
	return ;
}

int		get_last_data(t_plst *lst)
{
	t_plst *cur;

	cur = lst;
	while (cur->next)
		cur = cur->next;
	return (cur->data);
}

void	rotate_lst_data(t_plst *lst)
{
	int tmp;
	int last_data;
	t_plst *cur;

	last_data = get_last_data(lst);
	// ft_printf("last data %d\n", last_data);

	ft_printf("check rotate[]");
	if (lst->next && lst->data > last_data)
	{
		tmp = lst->data;
		lst->data = last_data;
		cur = lst;
		while (cur->next)
			cur = cur->next;
		cur->data = tmp;
		ft_printf("rotate first to last : \n");
		print_lst(lst);
	}
	return ; 
}

int		parse_arg(char **argv, t_plst **lst)
{
	int len;
	int total;

	len = 0;
	while (argv[len])
		len++;
	total = len;
	while (len - 1)
	{
		intert_lst_front(lst, new_lst(argv[len - 1]));
		len--;
	}
	return (total);
}

void	push_b(t_plst **lst, t_plst **lstb)
{
	int tmp;

	ft_printf("\npush b :\n");
	tmp = (*lst)->data;
	intert_lst_front(lstb, new_lst_nbr(tmp));

	*lst = (*lst)->next;

	ft_printf("a is :\n");
	print_lst(*lst);

	ft_printf("\nb is :\n");
	print_lst(*lstb);
}

void	do_sort(t_plst *lst, t_plst *lstb, int total)
{
	int steps;

	steps = 0;
	ft_printf("original :\n");
	print_lst(lst);

	while (total - 1)
	{
		rotate_lst_data(lst);
		swap_lst_data(lst);
		push_b(&lst, &lstb);

		rotate_lst_data(lstb);
		swap_lst_data(lstb);
		total--;
	}
}

int main(int argc, char **argv)
{
	t_plst *lst;
	t_plst *lstb;
	int total;

	if (argc < 2)
		ft_fprintf(2, "argument err\n");
	lst = NULL;
	lstb = NULL;
	total = parse_arg(argv, &lst);
	do_sort(lst, lstb, total);
}




