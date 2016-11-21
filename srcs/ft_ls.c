/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlistrat <vlistrat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/20 09:40:25 by vlistrat          #+#    #+#             */
/*   Updated: 2016/11/08 14:32:37 by vlistrat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

static t_ls		*ft_read_ls(t_df *df, t_ls *info, char *av)
{
	t_ls	*begin_list;
	t_ls	*first;
	t_ls	*line;

	first = NULL;
	line = NULL;
	while ((DP = readdir(DIRP)))
	{
		if (!first)
		{
			first = fill_info(first, df, av);
			info = first;
			begin_list = info;
		}
		else
		{
			line = fill_info(line, df, av);
			info->next = line;
			info = info->next;
		}
	}
	return (begin_list);
}

static t_ls		*get_list_ls(char *av, t_ls *info)
{
	t_df	*df;

	df = (t_df*)malloc(sizeof(t_df));
	if (ft_file_type(av))
	{
		if (!(DIRP = opendir(av)))
		{
			ft_error_ls(1, av);
			return (NULL);
		}
		info = ft_read_ls(df, info, av);
		closedir(DIRP);
	}
	else
		info = fill_file_info(info, df, av);
	free(df);
	return (info);
}

static int		hidden_ornot(t_ls *info, char *tag)
{
	if (!ft_strchr(tag, 'a') && NAME[0] == '.')
		return (0);
	return (1);
}

static int		recur_cond(t_ls *info, char *tag)
{
	if (RIGHTS[0] == 'd' && ft_strcmp(NAME, ".") != 0
			&& ft_strcmp(NAME, "..") != 0 && hidden_ornot(info, tag))
		return (1);
	return (0);
}

void			ft_ls(t_ls *info, char *av, char *tag)
{
	t_ls	*begin_list;

	if ((info = get_list_ls(av, info)))
	{
		info = sort_ls(info, tag);
		info = ft_display_ls(info, tag, ft_file_type(av));
		begin_list = info;
		while (info && ft_strchr(tag, 'R'))
		{
			if (recur_cond(info, tag))
			{
				ft_printf("\n%s:\n", info->path);
				ft_ls(RECUR, info->path, tag);
				free_info(RECUR);
			}
			info = info->next;
		}
		info = begin_list;
		free_info(info);
	}
}
