/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlistrat <vlistrat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/29 16:01:54 by vlistrat          #+#    #+#             */
/*   Updated: 2016/10/21 12:57:07 by vlistrat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

t_ls	*sort_ls(t_ls *info, char *tag)
{
	info = sort_list_ab(info);
	if (ft_strchr(tag, 'r'))
		info = sort_list_ba(info);
	if (!ft_strchr(tag, 'r') && ft_strchr(tag, 't'))
		info = sort_list_time_ab(info);
	else if (ft_strchr(tag, 'r') && ft_strchr(tag, 't'))
		info = sort_list_time_ba(info);
	return (info);
}
