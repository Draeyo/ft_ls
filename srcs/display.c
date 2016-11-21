/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlistrat <vlistrat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/11 08:26:52 by vlistrat          #+#    #+#             */
/*   Updated: 2016/11/08 14:05:36 by vlistrat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

static void		print_name(t_ls *info, char *tag)
{
	if (!is_hidden(tag, info))
	{
		if (RIGHTS[0] == 'd')
			ft_printf("\033[1;36m%s\033[0m", NAME);
		else if (RIGHTS[0] == 'l')
			ft_printf("\033[35m%s\033[0m", NAME);
		else if (RIGHTS[0] != 'd' && is_exec(RIGHTS))
			ft_printf("\033[31m%s\033[0m", NAME);
		else
			ft_printf("%s", NAME);
		if (LNTAR[0] != '\0')
			ft_printf(" -> %s ", LNTAR);
		ft_printf("\n");
	}
}

static void		print_rights(t_ls *info)
{
	if (ft_strchr(RIGHTS, '@') || ft_strchr(RIGHTS, '+'))
		ft_printf("%-11s", RIGHTS);
	else
		ft_printf("%-11s", RIGHTS);
}

static void		main_print(t_ls *info)
{
	print_rights(info);
	ft_printf(" %s ", PSLINK);
	ft_printf("%s  ", POWNER);
	ft_printf("%s  ", POWNGRP);
	if (info->rdev)
		ft_printf("%d, %d ", major(info->rdev), minor(info->rdev));
	else
		ft_printf("%s ", PSIZE);
	ft_printf("%s ", TIME);
}

static int		check_cont(t_ls *info, char *tag)
{
	t_ls	*comp;

	comp = info;
	while (comp->next)
		comp = comp->next;
	if (ft_strcmp(comp->dname, "..") == 0 && !ft_strchr(tag, 'a'))
		return (0);
	else if (!ft_strchr(tag, 'l'))
		return (0);
	return (1);
}

t_ls			*ft_display_ls(t_ls *info, char *tag, int bcode)
{
	t_ls	*begin_list;
	t_calc	*calc;

	begin_list = info;
	calc = (t_calc*)malloc(sizeof(t_calc));
	info = calc_blocks(info, calc);
	info = padding_ls(info, calc);
	if (bcode && check_cont(info, tag))
		ft_printf("total %d\n", TBLOCKS);
	while (info)
	{
		if (ft_strchr(tag, 'l') && !is_hidden(tag, info))
			main_print(info);
		print_name(info, tag);
		info = info->next;
	}
	free(calc);
	return (begin_list);
}
