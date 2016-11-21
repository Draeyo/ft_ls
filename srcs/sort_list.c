/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_list.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlistrat <vlistrat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/29 11:56:43 by vlistrat          #+#    #+#             */
/*   Updated: 2016/11/07 14:03:04 by vlistrat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

int		loop_again(t_ls **prev, t_ls **info, t_ls **next, t_ls **begin_list)
{
	*prev = NULL;
	*info = *begin_list;
	*next = (*begin_list)->next;
	return (0);
}

t_ls	*sort_list_ab(t_ls *info)
{
	t_ls	*begin_list;
	t_ls	*prev;
	t_ls	*tmp;
	t_ls	*next;
	int		a;

	begin_list = info;
	prev = NULL;
	next = info->next;
	a = 0;
	tmp = NULL;
	while (info->next)
	{
		if (ft_strcmp(NAME, next->dname) > 0)
			a += sort_ab(&info, &next, &prev, &begin_list);
		else
		{
			prev = info;
			info = next;
			next = next->next;
		}
		if (!info->next && a > 0)
			a = loop_again(&prev, &info, &next, &begin_list);
	}
	return (begin_list);
}

t_ls	*sort_list_ba(t_ls *info)
{
	t_ls	*begin_list;
	t_ls	*prev;
	t_ls	*tmp;
	t_ls	*next;
	int		a;

	begin_list = info;
	prev = NULL;
	next = info->next;
	a = 0;
	tmp = NULL;
	while (info->next)
	{
		if (ft_strcmp(NAME, next->dname) < 0)
			a += sort_ba(&info, &next, &prev, &begin_list);
		else
		{
			prev = info;
			info = next;
			next = next->next;
		}
		if (!info->next && a > 0)
			a = loop_again(&prev, &info, &next, &begin_list);
	}
	return (begin_list);
}
