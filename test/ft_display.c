/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_display.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlistrat <vlistrat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/17 19:03:19 by vlistrat          #+#    #+#             */
/*   Updated: 2016/03/17 19:03:56 by vlistrat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

t_file	*ft_display_la(t_file *lst)
{
	t_file	*begin_list;

	begin_list = lst;
	while (lst)
	{
		ft_putstr(lst->rights);
		ft_putstr("  ");
		ft_putstr(lst->symlinks);
		ft_putstr("  ");
		ft_putstr(lst->owner);
		ft_putstr("  ");
		ft_putstr(lst->group);
		ft_putstr("  ");
		ft_putstr(lst->size);
		ft_putstr(" ");
		ft_putstr(lst->time);
		ft_putstr(" ");
		ft_putendl(lst->name);
		lst = lst->next;
	}
	return (begin_list);
}
