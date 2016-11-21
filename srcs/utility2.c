/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utility2.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlistrat <vlistrat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/07 08:01:30 by vlistrat          #+#    #+#             */
/*   Updated: 2016/11/08 14:39:34 by vlistrat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

int		is_hidden(char *tag, t_ls *info)
{
	if (!ft_strchr(tag, 'a') && NAME[0] == '.')
		return (1);
	return (0);
}

t_ls	*calc_blocks(t_ls *info, t_calc *calc)
{
	t_ls	*begin_list;

	begin_list = info;
	TBLOCKS = 0;
	while (info)
	{
		TBLOCKS += BLOCKS;
		info = info->next;
	}
	return (begin_list);
}
