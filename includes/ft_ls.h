/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlistrat <vlistrat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/19 13:55:35 by vlistrat          #+#    #+#             */
/*   Updated: 2016/11/08 11:51:27 by vlistrat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_LS_H
# define FT_LS_H

# include "libft.h"
# include "ft_printf.h"
# include "get_next_line.h"

# include <sys/types.h>
# include <sys/stat.h>
# include <sys/xattr.h>
# include <sys/acl.h>

# include <uuid/uuid.h>

# include <dirent.h>
# include <stdlib.h>
# include <stdio.h>
# include <string.h>
# include <unistd.h>
# include <fcntl.h>
# include <pwd.h>
# include <grp.h>
# include <time.h>
# include <errno.h>

# define DIRP df->dirp
# define DP df->dp
# define STAT df->stat
# define PASSWD df->passwd
# define GRP df->grp

# define TIME info->time
# define RIGHTS info->rights
# define PATH elem->path
# define INEXT info->next
# define IPREV info->prev
# define BLOCKS info->blocks
# define OWNER info->owner
# define POWNER info->p_owner
# define OWNGRP info->grp
# define POWNGRP info->p_grp
# define FSIZE info->size
# define PSIZE info->p_size
# define NAME info->dname
# define SLINK info->symlinks
# define PSLINK info->p_symlinks
# define E_TIME info->etime
# define RECUR info->recur
# define LNTAR info->lntar

# define DNAME df->dp->d_name

# define UID stat.st_uid
# define GID stat.st_gid
# define SIZE stat.st_size
# define MTIME stat.st_mtime
# define NLINK stat.st_nlink
# define MODE stat.st_mode

# define PWNAME df->passwd->pw_name

# define GRNAME df->grp->gr_name

# define TBLOCKS calc->t_blocks
# define MSLINK calc->max_slink
# define MSIZE calc->max_size
# define MOWN calc->max_own
# define MGRP calc->max_grp

typedef struct		s_df
{
	DIR				*dirp;
	struct dirent	*dp;
	struct passwd	*passwd;
	struct group	*grp;
}					t_df;

typedef struct		s_ls
{
	char			*time;
	time_t			etime;
	time_t			nstime;
	char			*rights;
	char			*path;
	char			*owner;
	char			*p_owner;
	char			*grp;
	char			*p_grp;
	int				blocks;
	int				size;
	dev_t			rdev;
	char			*p_size;
	int				symlinks;
	char			*p_symlinks;
	char			*dname;
	char			lntar[256];
	struct s_ls		*next;
	struct s_ls		*recur;
}					t_ls;

typedef struct		s_calc
{
	int		t_blocks;
	int		max_slink;
	int		max_size;
	int		max_own;
	int		max_grp;
}					t_calc;

/*
** MAIN
*/
void				ft_ls(t_ls *info, char *av, char *tag);

int					ft_file_type(char *av);

t_ls				*fill_info(t_ls *elem, t_df *df, char *av);
t_ls				*fill_file_info(t_ls *elem, t_df *df, char *av);
/*
** RIGHTS
*/
char				*get_rights(struct stat stat, char *rights);

/*
** TIME
*/
char				*get_time(struct stat stat);

/*
** OPTIONS
*/
int					get_tag(char *tag, char **av);

/*
** DISPLAY
*/
t_ls				*ft_display_ls(t_ls *info, char *tag, int bcode);

t_ls				*max_own(t_ls *info, t_calc *calc);
t_ls				*calc_msize(t_ls *info, t_calc *calc);
t_ls				*padding_ls(t_ls *info, t_calc *calc);

/*
** UTILITY
*/
char				*path_join(char *s1, char *s2);
char				*pad_right(int nb, int len);
char				*pad_left(char *str, int len);
char				**sort_args(char **av);

void				free_info(t_ls *info);
void				free_args(char **args);

int					is_exec(char *rights);
int					is_hidden(char *tag, t_ls *info);
int					loop_again(t_ls **prev, t_ls **info, t_ls **next,
		t_ls **begin_list);

int					sort_list_ns_ab(t_ls **info, t_ls **next, t_ls **prev,
		t_ls **b_list);
int					sort_list_ns_ba(t_ls **info, t_ls **next, t_ls **prev,
		t_ls **b_list);
int					sort_ab(t_ls **info, t_ls **next, t_ls **prev,
		t_ls **b_list);
int					sort_ba(t_ls **info, t_ls **next, t_ls **prev,
		t_ls **b_list);

t_ls				*sort_list_ab(t_ls *info);
t_ls				*sort_list_ba(t_ls *info);
t_ls				*sort_list_time_ab(t_ls *info);
t_ls				*sort_list_time_ba(t_ls *info);
t_ls				*sort_ls(t_ls *info, char *tag);

t_ls				*check_xattr(t_ls *info, int *a);
t_ls				*calc_blocks(t_ls *info, t_calc *calc);

/*
** ERRORS
*/
int					ft_error_ls(int ecode, char *status);

#endif
