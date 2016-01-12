/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itohex.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlistrat <vlistrat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/11 13:33:22 by vlistrat          #+#    #+#             */
/*   Updated: 2016/01/11 20:35:44 by vlistrat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char		*ft_strrev(char *str)
{
	char	*buf;
	int		i;
	int		j;

	i = 0;
	j = ft_strlen(str) - 1;
	buf = ft_strnew(ft_strlen(str) - 1);
	while (j > -1)
		buf[i++] = str[j--];
	free(buf);
	return (buf);
}


char			*ft_itohex(unsigned int nb)
{
	char	*str;
	int		i;

	str = ft_strnew(40);
	i = 0;
	if (nb == 0)
		str[0] = '0';
	while (nb != 0)
	{
		if (nb % 16 < 10)
			str[i] = (nb % 16) + 48;
		else if (nb % 16 >= 10)
			str[i] = (nb % 16) - 10 + 97;
		nb /= 16;
		i++;
	}
	str = ft_strrev(str);
	return (str);
}
