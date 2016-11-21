/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utility.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlistrat <vlistrat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/20 10:23:50 by vlistrat          #+#    #+#             */
/*   Updated: 2016/11/07 14:16:26 by vlistrat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

char	*path_join(char *s1, char *s2)
{
	int		i;
	char	*cpy;
	size_t	len;

	i = 0;
	if (!s1 && !s2)
		return (NULL);
	else if (!s1 || !s2)
		return ((s2 ? s2 : s1));
	len = ft_strlen(s1) + ft_strlen(s2) + 1;
	cpy = ft_strnew(len + 1);
	while (*s1)
	{
		cpy[i] = *s1++;
		i++;
	}
	if (cpy[i - 1] != '/')
		cpy[i++] = '/';
	while (*s2)
	{
		cpy[i] = *s2++;
		i++;
	}
	return (cpy);
}

char	*pad_right(int nb, int len)
{
	int		i;
	int		j;
	char	*ret;
	char	*str;

	str = ft_xtoa(nb);
	i = ft_strlen(str) - 1;
	j = len - 1;
	ret = ft_strnew(len);
	while (i > -1)
	{
		ret[j] = str[i];
		i--;
		j--;
	}
	while (j > -1)
	{
		ret[j] = ' ';
		j--;
	}
	free(str);
	return (ret);
}

char	*pad_left(char *str, int len)
{
	int		i;
	char	*ret;

	i = 0;
	ret = ft_strnew(len);
	while (str[i])
	{
		ret[i] = str[i];
		i++;
	}
	while (i < len)
	{
		ret[i] = ' ';
		i++;
	}
	free(str);
	return (ret);
}

int		is_exec(char *rights)
{
	if (rights[3] == 'x' || rights[6] == 'x' || rights[9] == 'x')
		return (1);
	return (0);
}

int		ft_file_type(char *av)
{
	struct stat		stat;

	lstat(av, &stat);
	if (S_ISDIR(MODE))
		return (1);
	else
		return (0);
}
