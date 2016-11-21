/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlistrat <vlistrat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/20 09:40:25 by vlistrat          #+#    #+#             */
/*   Updated: 2016/11/08 14:41:12 by vlistrat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

static t_ls		*fill_common(t_ls *elem, t_df *df, struct stat stat)
{
	if (stat.st_rdev)
		elem->rdev = stat.st_rdev;
	else
		elem->rdev = 0;
	if ((PASSWD = getpwuid(UID)))
		elem->owner = ft_strdup(PWNAME);
	else
		elem->owner = ft_xtoa(stat.st_uid);
	if ((GRP = getgrgid(GID)))
		elem->grp = ft_strdup(GRNAME);
	else
		elem->grp = ft_xtoa(stat.st_gid);
	elem->rights = get_rights(stat, elem->rights);
	if (listxattr(PATH, NULL, 0, XATTR_NOFOLLOW) > 0)
		elem->rights[10] = '@';
	else if (acl_get_file(PATH, ACL_TYPE_EXTENDED))
		elem->rights[10] = '+';
	elem->blocks = stat.st_blocks;
	elem->size = SIZE;
	elem->symlinks = NLINK;
	return (elem);
}

static char		*get_file_path(char *av)
{
	char	*ret;

	ret = NULL;
	if (av[0] == '.' && av[1] == '/')
		return ((ret = ft_strsub(av, 2, ft_strlen(av) - 2)));
	else
		return ((ret = ft_strdup(av)));
}

t_ls			*fill_info(t_ls *elem, t_df *df, char *av)
{
	struct stat		stat;
	int				rlsize;

	rlsize = 0;
	elem = (t_ls*)malloc(sizeof(t_ls));
	PATH = path_join(av, DNAME);
	if (lstat(PATH, &stat) < 0)
		ft_error_ls(1, PATH);
	if ((rlsize = readlink(PATH, elem->lntar, 256)) < 0)
		rlsize = 0;
	elem->lntar[rlsize] = '\0';
	elem->time = get_time(stat);
	elem->etime = stat.st_mtime;
	elem->nstime = (stat.st_mtimespec).tv_nsec;
	elem->dname = ft_strdup(DNAME);
	elem->next = NULL;
	elem->recur = NULL;
	elem = fill_common(elem, df, stat);
	return (elem);
}

t_ls			*fill_file_info(t_ls *elem, t_df *df, char *av)
{
	struct stat		stat;
	int				rlsize;

	rlsize = 0;
	elem = (t_ls*)malloc(sizeof(t_ls));
	PATH = get_file_path(av);
	if (lstat(PATH, &stat) < 0)
		ft_error_ls(1, PATH);
	if ((rlsize = readlink(PATH, elem->lntar, 256)) < 0)
		rlsize = 0;
	elem->lntar[rlsize] = '\0';
	elem->time = get_time(stat);
	elem->etime = stat.st_mtime;
	elem->nstime = (stat.st_mtimespec).tv_nsec;
	elem->dname = ft_strdup(PATH);
	elem->next = NULL;
	elem->recur = NULL;
	elem = fill_common(elem, df, stat);
	return (elem);
}
