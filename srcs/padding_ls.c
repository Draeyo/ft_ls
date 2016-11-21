/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   padding_ls.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlistrat <vlistrat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/29 16:51:26 by vlistrat          #+#    #+#             */
/*   Updated: 2016/10/26 09:43:42 by vlistrat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

t_ls	*max_own(t_ls *info, t_calc *calc)
{
	t_ls	*begin_list;

	begin_list = info;
	MOWN = 0;
	MGRP = 0;
	while (info)
	{
		if ((int)ft_strlen(OWNER) > MOWN)
			MOWN = (int)ft_strlen(OWNER);
		info = info->next;
	}
	info = begin_list;
	while (info)
	{
		if ((int)ft_strlen(OWNGRP) > MGRP)
			MGRP = (int)ft_strlen(OWNGRP);
		info = info->next;
	}
	return (begin_list);
}

t_ls	*calc_msize(t_ls *info, t_calc *calc)
{
	t_ls	*begin_list;

	begin_list = info;
	MSLINK = 0;
	MSIZE = 0;
	while (info)
	{
		if ((int)ft_nblen(SLINK) > MSLINK)
			MSLINK = (int)ft_nblen(SLINK);
		info = info->next;
	}
	info = begin_list;
	while (info)
	{
		if ((int)ft_nblen(FSIZE) > MSIZE)
			MSIZE = (int)ft_nblen(FSIZE);
		info = info->next;
	}
	return (begin_list);
}

t_ls	*padding_ls(t_ls *info, t_calc *calc)
{
	t_ls	*begin_list;

	info = max_own(info, calc);
	info = calc_msize(info, calc);
	begin_list = info;
	while (info)
	{
		PSLINK = pad_right(SLINK, MSLINK);
		PSIZE = pad_right(FSIZE, MSIZE);
		POWNER = pad_left(OWNER, MOWN);
		POWNGRP = pad_left(OWNGRP, MGRP);
		info = info->next;
	}
	return (begin_list);
}
