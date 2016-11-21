/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rights.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlistrat <vlistrat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/19 16:21:17 by vlistrat          #+#    #+#             */
/*   Updated: 2016/10/31 08:26:30 by vlistrat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

static char		ft_filetype(struct stat stat)
{
	if (S_ISDIR(MODE))
		return ('d');
	else if (S_ISBLK(MODE))
		return ('b');
	else if (S_ISCHR(MODE))
		return ('c');
	else if (S_ISLNK(MODE))
		return ('l');
	else if (S_ISSOCK(MODE))
		return ('s');
	else if (S_ISFIFO(MODE))
		return ('p');
	else if (S_ISREG(MODE))
		return ('-');
	else
		return ('u');
}

static char		ft_sid(struct stat stat, int a)
{
	if (a == 1 && !(MODE & S_IXUSR) && (MODE & S_ISUID))
		return ('S');
	else if (a == 1 && (MODE & S_IXUSR) && (MODE & S_ISUID))
		return ('s');
	else if (a == 2 && !(MODE & S_IXGRP) && (MODE & S_ISGID))
		return ('S');
	else if (a == 2 && (MODE & S_IXGRP) && (MODE & S_ISGID))
		return ('s');
	else if (a == 3 && !(MODE & S_IXOTH) && (MODE & S_ISVTX))
		return ('T');
	else if (a == 3 && (MODE & S_IXOTH) && (MODE & S_ISVTX))
		return ('t');
	else if (a == 1 && (MODE & S_IXUSR))
		return ('x');
	else if (a == 2 && (MODE & S_IXGRP))
		return ('x');
	else if (a == 3 && (MODE & S_IXOTH))
		return ('x');
	else
		return ('-');
}

char			*get_rights(struct stat stat, char *rights)
{
	rights = ft_strnew(11);
	rights[0] = ft_filetype(stat);
	rights[1] = (MODE & S_IRUSR ? 'r' : '-');
	rights[2] = (MODE & S_IWUSR ? 'w' : '-');
	rights[3] = ft_sid(stat, 1);
	rights[4] = (MODE & S_IRGRP ? 'r' : '-');
	rights[5] = (MODE & S_IWGRP ? 'w' : '-');
	rights[6] = ft_sid(stat, 2);
	rights[7] = (MODE & S_IROTH ? 'r' : '-');
	rights[8] = (MODE & S_IWOTH ? 'w' : '-');
	rights[9] = ft_sid(stat, 3);
	return (rights);
}
