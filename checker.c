/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lwang <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/19 12:21:02 by lwang             #+#    #+#             */
/*   Updated: 2017/05/19 12:21:14 by lwang            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

static int	checker_moves(char *line, t_plst **lst, t_plst **lstb)
{
	if (start_moves(line, lst, lstb))
	{
		deep_free(*lst);
		deep_free(*lstb);
		free(line);
		line = NULL;
		get_next_line(-42, NULL);
		ft_fprintf(2, "Error\n");
		return (1);
	}
	return (0);
}

static void	free_everything(t_plst *lst, t_plst *lstb)
{
	deep_free(lst);
	deep_free(lstb);
}

int			main(int argc, char **argv)
{
	t_plst	*lst;
	t_plst	*lstb;
	char	*line;
	t_pinfo	info;

	if (argc < 2)
		return (0);
	ft_memset(&info, 0, sizeof(t_pinfo));
	lst = NULL;
	lstb = NULL;
	if (parse_arg(argc, argv, &lst, &info))
		return (ft_fprintf(2, "Error\n"));
	while (get_next_line(0, &line))
	{
		if (checker_moves(line, &lst, &lstb))
			return (1);
		free(line);
	}
	if (!check_all_inorder(lst) || lstb)
		ft_printf(ft_strchr(info.flag, 'c') ? RED"KO\n"CLN : "KO\n");
	else
		ft_printf(ft_strchr(info.flag, 'c') ? GREE"OK\n"CLN : "OK\n");
	free_everything(lst, lstb);
}
