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

void	print_lst(t_list *list)
{
	t_list *cur;

	cur = list;
	while (cur)
	{
		ft_printf("%d\n", ft_atoi(cur->content));
		cur = cur->next;
	}
}

void	parse_arg(char **argv, t_pinfo *info)
{
	int len;

	len = 0;
	while (argv[len])
		len++;
	while (len - 1)
	{
		ft_lstadd(&info->lst, ft_lstnew(argv[len - 1], ft_strlen(argv[len - 1]) + 1));
		len--;
	}
}

// void	do_sort(t_list *lst)
// {
// 	t_list *cur;

// 	cur = lst;
// 	if (ft_atoi(lst->content) > ft_atoi(lst->next->content))
// 	{	
// 		lst->content = ft_strdup(lst->next->content);
// 		lst->content_size = lst->next->content_size;
// 		lst->next = 
// 	}
// }

int main(int argc, char **argv)
{
	t_pinfo info;

	if (argc < 2)
		ft_fprintf(2, "argument err\n");
	ft_memset(&info, 0, sizeof(t_pinfo));
	parse_arg(argv, &info);
	// do_sort(info);
	print_lst(info.lst);
}
