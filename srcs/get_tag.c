/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_tag.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlistrat <vlistrat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/20 10:37:08 by vlistrat          #+#    #+#             */
/*   Updated: 2016/10/31 08:33:18 by vlistrat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

static	int		is_lstag_letter(char c)
{
	if (c == 'R' || c == 'l' || c == 'a' || c == 'r' || c == 't')
		return (1);
	else if (c == '-' || c == ' ')
		return (2);
	return (0);
}

static int		minus_excess(char *str)
{
	if (str[0] == '-' && str[1] == '-' && str[2] != ' ')
		return (0);
	return (1);
}

static int		is_lstag(char *tag, char *str)
{
	int			i;
	static int	j;

	i = 0;
	j = 0;
	if (str[i] != '-')
		return (0);
	while (str[i])
	{
		if (!minus_excess(&str[i]))
			ft_error_ls(3, &str[i]);
		else if (!is_lstag_letter(str[i]))
			ft_error_ls(2, &str[i]);
		if (is_lstag_letter(str[i]) == 1)
		{
			if (!ft_strchr(tag, str[i]))
				tag[j] = str[i];
			j++;
		}
		i++;
	}
	return (1);
}

int				get_tag(char *tag, char **av)
{
	int		i;

	i = 1;
	while (av[i] && is_lstag(tag, av[i]))
		i++;
	return (i);
}
