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

void	double_free(char **av)
{
	int	i;

	i = 0;
	while (av[i])
	{
		free(av[i]);
		av[i] = NULL;
		i++;
	}
	free(av);
	av = NULL;
}

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

int		get_len(char **av)
{
	int i;

	i = 0;
	while (av[i])
		i++;
	return (i);
}

int		parse_arg(int argc, char **argv, t_plst **lst)
{
<<<<<<< HEAD
=======
	// char	**av;
>>>>>>> dcfa9d8b7ec023be26595049dec96f5484579eb6
	(void)argc;
	int		len;

	len = 0;
<<<<<<< HEAD
=======
	// av = argv;
	// if (argc == 2)
	// {
	// 	av = ft_strsplit(argv[1], ' ');
	// 	if (get_len(av) == 1 && !(check_arg(av)))
	// 	{
	// 		double_free(av);
	// 		return (2);
	// 	}
	// 	else if (get_len(av) == 1 && (check_arg(av)))
	// 	{
	// 		return (1);
	// 	}
	// }
	// if (argc == 2 && check_arg(av))
	// {
	// 	double_free(av);
	// 	return (1);
	// }
>>>>>>> dcfa9d8b7ec023be26595049dec96f5484579eb6
	if (check_arg(argv))
		return (1);
	while (argv[len])
		len++;
	while (len - 1)
	{
		intert_lst_front(lst, new_lst(argv[len - 1]));
		len--;
	}
<<<<<<< HEAD
=======
	// if (argc == 2 && len == 1)
	// 	intert_lst_front(lst, new_lst(argv[0]));
	// if (argc == 2)
	// 	double_free(argv);
>>>>>>> dcfa9d8b7ec023be26595049dec96f5484579eb6
	return (0);
}
