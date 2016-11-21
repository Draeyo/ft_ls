/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_args.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlistrat <vlistrat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/31 08:25:48 by vlistrat          #+#    #+#             */
/*   Updated: 2016/11/07 08:15:13 by vlistrat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

static int	ft_argslen(char **av)
{
	int	i;

	i = 0;
	while (av[i])
		i++;
	return (i);
}

static char	case_file(char **av, int i, char **ret, int j)
{
	if (!ft_file_type(av[i]))
	{
		ret[j] = ft_strdup(av[i]);
		return (++j);
	}
	return (j);
}

static char	case_dir(char **av, int i, char **ret, int j)
{
	if (ft_file_type(av[i]))
	{
		ret[j] = ft_strdup(av[i]);
		return (++j);
	}
	return (j);
}

char		**sort_args(char **av)
{
	char	**ret;
	int		i;
	int		j;

	i = 0;
	j = 0;
	ret = (char**)malloc(sizeof(*ret) * ft_argslen(av) + 1);
	while (av[i])
	{
		j = case_file(av, i, ret, j);
		i++;
	}
	i = 0;
	while (av[i])
	{
		j = case_dir(av, i, ret, j);
		i++;
	}
	ret[j] = NULL;
	return (ret);
}
