/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_list_time.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlistrat <vlistrat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/29 16:01:06 by vlistrat          #+#    #+#             */
/*   Updated: 2016/11/07 14:15:46 by vlistrat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

static int		sort_t_ab(t_ls **info, t_ls **next, t_ls **prev, t_ls **b_list)
{
	t_ls	*tmp;
	int		a;

	tmp = NULL;
	a = 0;
	if ((*info)->etime < (*next)->etime)
	{
		(*info)->next = (*next)->next;
		(*next)->next = *info;
		if (*b_list == *info)
			*b_list = *next;
		if (*prev)
			(*prev)->next = *next;
		*prev = *next;
		tmp = *info;
		*info = *next;
		*next = tmp;
		a = 1;
	}
	return (a);
}

static int		sort_t_ba(t_ls **info, t_ls **next, t_ls **prev, t_ls **b_list)
{
	t_ls	*tmp;
	int		a;

	tmp = NULL;
	a = 0;
	if ((*info)->etime > (*next)->etime)
	{
		(*info)->next = (*next)->next;
		(*next)->next = *info;
		if (*b_list == *info)
			*b_list = *next;
		if (*prev)
			(*prev)->next = *next;
		*prev = *next;
		tmp = *info;
		*info = *next;
		*next = tmp;
		a = 1;
	}
	return (a);
}

t_ls			*sort_list_time_ab(t_ls *info)
{
	t_ls	*begin_list;
	t_ls	*prev;
	t_ls	*next;
	int		a;

	begin_list = info;
	prev = NULL;
	next = info->next;
	a = 0;
	while (info->next)
	{
		if (E_TIME < next->etime)
			a += sort_t_ab(&info, &next, &prev, &begin_list);
		else if (E_TIME == next->etime && info->nstime < next->nstime)
			a += sort_list_ns_ab(&info, &next, &prev, &begin_list);
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

t_ls			*sort_list_time_ba(t_ls *info)
{
	t_ls	*begin_list;
	t_ls	*prev;
	t_ls	*next;
	int		a;

	begin_list = info;
	prev = NULL;
	next = info->next;
	a = 0;
	while (info->next)
	{
		if (E_TIME > next->etime)
			a += sort_t_ba(&info, &next, &prev, &begin_list);
		else if (E_TIME == next->etime && info->nstime > info->nstime)
			a += sort_list_ns_ba(&info, &next, &prev, &begin_list);
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
