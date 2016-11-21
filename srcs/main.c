/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlistrat <vlistrat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/19 13:57:28 by vlistrat          #+#    #+#             */
/*   Updated: 2016/11/08 11:11:23 by vlistrat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

static void		args_ls(char **av, int ac, t_ls *info)
{
	char	**args;
	int		mult;
	char	*tag;
	int		i;

	mult = 0;
	tag = ft_strnew(6);
	i = get_tag(tag, av);
	args = sort_args(&av[i]);
	if (ac > 2 && av[i + 1])
		mult = 1;
	i = 0;
	while (args[i])
	{
		if (mult && ft_file_type(args[i]))
			ft_printf("%s:\n", args[i]);
		ft_ls(info, args[i], tag);
		i++;
		if (mult && args[i] && ft_file_type(args[i]))
			ft_printf("\n");
	}
	free_args(args);
	free(tag);
}

int				main(int ac, char **av)
{
	t_ls	*info;
	char	*tag;
	int		i;

	info = NULL;
	tag = ft_strnew(6);
	i = get_tag(tag, av);
	if (ac < 2 || (i > 1 && !av[i]))
		ft_ls(info, ".", tag);
	else
		args_ls(av, ac, info);
	free(tag);
	return (0);
}
