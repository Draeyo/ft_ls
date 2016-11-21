/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_error_ls.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlistrat <vlistrat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/19 16:40:37 by vlistrat          #+#    #+#             */
/*   Updated: 2016/11/08 13:55:57 by vlistrat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

int		ft_error_ls(int ecode, char *status)
{
	ft_putstr_fd("ft_ls: ", 2);
	if (ecode == 1)
	{
		ft_putstr_fd(status, 2);
		if (errno == EACCES)
			ft_putendl_fd(": Permission denied", 2);
		else
		{
			ft_putendl_fd(": No such file or directory", 2);
			exit(EXIT_SUCCESS);
		}
	}
	else if (ecode == 2 || ecode == 3)
	{
		ft_putstr_fd("illegal option -- ", 2);
		write(2, &status[0], 1);
		ft_putendl_fd("\nusage: ft_ls [-Ralrt] [file ...]", 2);
		exit(EXIT_SUCCESS);
	}
	return (0);
}
