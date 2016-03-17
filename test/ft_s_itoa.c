/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_s_itoa.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlistrat <vlistrat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/17 17:14:12 by vlistrat          #+#    #+#             */
/*   Updated: 2016/03/09 13:26:54 by vlistrat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

static int		calc_len(int nb)
{
	int		len;

	len = 0;
	if (nb < 0)
		return ((len = ft_nblen(nb) - 1));
	else
		return ((len = ft_nblen(nb)));
}

static int		calc_div(int len)
{
	int		div;

	div = 1;
	while (--len)
		div *= 10;
	return (div);
}

char			*ft_s_itoa(int nb)
{
	int		div;
	char	*ret;
	int		len;
	int		i;

	i = 0;
	len = calc_len(nb);
	div = calc_div(len);
	ret = ft_strnew(len + 1);
	if (nb < 0)
	{
		ret[i] = '-';
		nb *= -1;
		i++;
	}
	else if (nb == 0)
		return ("0");
	while (len--)
	{
		ret[i] = ((nb / div) + 48);
		nb -= ((nb / div) * div);
		div /= 10;
		i++;
	}
	return (ret);
}
