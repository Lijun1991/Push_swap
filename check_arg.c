/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_arg.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lwang <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/19 17:36:12 by lwang             #+#    #+#             */
/*   Updated: 2017/05/19 17:36:14 by lwang            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

int		ck_is_nbr(char *s)
{
	int i;

	i = 0;
	while (s[i])
	{
		if (s[i] < 48 || s[i] > 59)
			return (1);
		i++;
	}
	return(0);
}

int		ck_is_int(char *s)
{
	long long	tmp;
	int			i;

	i = 0;
	tmp = 0;
	while (s[i])
	{
		if (ft_strlen(s) > 11)
			return (1);
		tmp = ft_atoi(s);
		if (tmp > 2147483647 || tmp < -2147483648)
			return (1);
		i++;
	}
	return (0);
}

int		ck(int i, char *s, char **av)
{
	int j;

	j = 0;
	while (av[j])
	{
		if (j != i && !ft_strcmp(s, av[j]))
			return (1);
		j++;
	}
	return (0);
}

int		ck_dup(char **argv)
{
	int i;
	char *s;

	i = 1;
	s = NULL;
	while (argv[i])
	{
		s = ft_strdup(argv[i]);
		if (ck(i, s, argv))
		{
			free(s);
			return (1);
		}
		i++;
	}
	return (0);
}

int		check_arg(char **argv)
{
	int	i;

	i = 1;
	while (argv[i])
	{
		if (ck_is_nbr(argv[i]) || ck_is_int(argv[i]))
			return (1);
		i++;
	}
	if (ck_dup(argv))
		return (1);
	return (0);
}