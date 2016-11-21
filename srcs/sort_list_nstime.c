/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_list_nstime.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlistrat <vlistrat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/07 14:07:34 by vlistrat          #+#    #+#             */
/*   Updated: 2016/11/07 14:15:19 by vlistrat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

int		sort_list_ns_ab(t_ls **info, t_ls **next, t_ls **prev, t_ls **b_lst)
{
	t_ls	*tmp;
	int		a;

	tmp = NULL;
	a = 0;
	if ((*info)->nstime < (*next)->nstime)
	{
		(*info)->next = (*next)->next;
		(*next)->next = *info;
		if (*b_lst == *info)
			*b_lst = *next;
		if (*prev)
			(*prev)->next = *next;
		*prev = *next;
		tmp = *info;
		*info = *next;
		*next = tmp;
	}
	return (a);
}

int		sort_list_ns_ba(t_ls **info, t_ls **next, t_ls **prev, t_ls **b_lst)
{
	t_ls	*tmp;
	int		a;

	tmp = NULL;
	a = 0;
	if ((*info)->nstime > (*next)->nstime)
	{
		(*info)->next = (*next)->next;
		(*next)->next = *info;
		if (*b_lst == *info)
			*b_lst = *next;
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

int		sort_ab(t_ls **info, t_ls **next, t_ls **prev, t_ls **b_lst)
{
	t_ls	*tmp;
	int		a;

	tmp = NULL;
	a = 0;
	if (ft_strcmp((*info)->dname, (*next)->dname) > 0)
	{
		(*info)->next = (*next)->next;
		(*next)->next = (*info);
		if ((*b_lst) == (*info))
			(*b_lst) = (*next);
		if ((*prev))
			(*prev)->next = (*next);
		*prev = *next;
		tmp = *info;
		*info = *next;
		*next = tmp;
		a = 1;
	}
	return (a);
}

int		sort_ba(t_ls **info, t_ls **next, t_ls **prev, t_ls **b_lst)
{
	t_ls	*tmp;
	int		a;

	tmp = NULL;
	a = 0;
	if (ft_strcmp((*info)->dname, (*next)->dname) < 0)
	{
		(*info)->next = (*next)->next;
		(*next)->next = *info;
		if (*b_lst == *info)
			*b_lst = *next;
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
