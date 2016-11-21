/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_alloc_ls.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlistrat <vlistrat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/31 08:23:59 by vlistrat          #+#    #+#             */
/*   Updated: 2016/11/05 10:57:55 by vlistrat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void	free_info(t_ls *info)
{
	while (info)
	{
		if (TIME)
			free(TIME);
		if (POWNER)
			free(POWNER);
		if (POWNGRP)
			free(POWNGRP);
		if (RIGHTS)
			free(RIGHTS);
		if (NAME)
			free(NAME);
		if (info->path)
			free(info->path);
		if (PSLINK)
			free(PSLINK);
		if (PSIZE)
			free(PSIZE);
		if (RECUR)
			free_info(RECUR);
		free(info);
		info = info->next;
	}
}

void	free_args(char **args)
{
	int	i;

	i = 0;
	while (args[i])
	{
		free(args[i]);
		i++;
	}
	free(args[i]);
	free(args);
}
