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

int				check_all_inorder(t_plst *lst)
{
	t_plst	*cur;
	int		tmp;
	int		len;

	cur = lst;
	tmp = 0;
	len = count_nbr(lst);
	if (lst)
	{
		while (cur->next)
		{
			tmp = cur->next->data;
			if (tmp < cur->data)
				break ;
			cur = cur->next;
			len--;
		}
	}
	if (len == 1)
		return (1);
	return (0);
}

static int		check_flag(char *s, t_pinfo *info, int *j)
{
	if (s[1] == 'v' && s[2] == '\0' && !ft_strchr(info->flag, 'v'))
		info->flag[(*j)++] = 'v';
	else if (s[1] == 'c' && s[2] == '\0' && !ft_strchr(info->flag, 'c'))
		info->flag[(*j)++] = 'c';
	else if (s[1] == 'o' && s[2] == '\0' && !ft_strchr(info->flag, 'o'))
		info->flag[(*j)++] = 'o';
	else if (s[1] == 'n' && s[2] == '\0' && !ft_strchr(info->flag, 'n'))
		info->flag[(*j)++] = 'n';
	else if (s[1] == 's' && s[2] == '\0' && !ft_strchr(info->flag, 's'))
		info->flag[(*j)++] = 's';
	else
		return (1);
	return (0);
}

static char		**get_flag(int argc, char **argv, t_pinfo *info)
{
	int	i;
	int	j;

	i = 1;
	j = 0;
	while (i < argc)
	{
		if (argv[i][0] == '-')
		{
			if (ft_isdigit(argv[i][1]))
				break ;
			if (check_flag(argv[i], info, &j))
				break ;
		}
		else
			break ;
		i++;
	}
	while (i-- > 1)
		argv++;
	return (argv);
}

int				parse_arg(int argc, char **argv, t_plst **lst, t_pinfo *info)
{
	int		len;
	char	**av;

	len = 0;
	av = get_flag(argc, argv, info);
	if (check_arg(av))
		return (1);
	while (av[len])
		len++;
	if (len == 1)
		return (1);
	while (len - 1)
	{
		intert_lst_front(lst, new_lst(av[len - 1]));
		len--;
	}
	return (0);
}
