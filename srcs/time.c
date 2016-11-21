/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   time.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlistrat <vlistrat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/19 16:25:17 by vlistrat          #+#    #+#             */
/*   Updated: 2016/11/08 11:14:32 by vlistrat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

static char		*get_year(int i, int start, char *timestr)
{
	char	*ret;
	char	*first;
	char	*second;
	char	*space;
	char	*pnt;

	ret = NULL;
	i -= 2;
	first = ft_strsub(timestr, start, i - start);
	pnt = first;
	second = ft_strsub(timestr, ft_strlen(timestr) - 5, 4);
	space = " ";
	first = ft_strjoin(first, space);
	free(pnt);
	ret = ft_strjoin(first, second);
	free(first);
	free(second);
	return (ret);
}

char			*get_time(struct stat stat)
{
	char	*timestr;
	char	*ret;
	int		start;
	int		i;

	i = 0;
	start = 0;
	ret = NULL;
	if (!(timestr = ctime(&MTIME)))
		return (NULL);
	while (timestr[start] != ' ')
		start++;
	start++;
	while (timestr[i] != ':')
		i++;
	if (MTIME <= (time(0) - 15778458) || MTIME >= (time(0) + 15778458))
		ret = get_year(i, start, timestr);
	else
	{
		i += 3;
		ret = ft_strsub(timestr, start, i - start);
	}
	return (ret);
}
