/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlistrat <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/27 12:31:00 by vlistrat          #+#    #+#             */
/*   Updated: 2016/01/11 13:23:14 by vlistrat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int		ft_div(unsigned int nb)
{
	int		i;
	int		ret;

	i = 0;
	ret = 1;
	while (nb > 10)
	{
		nb /= 10;
		i++;
	}
	while (i > 0)
	{
		ret *= 10;
		i--;
	}
	return (ret);
}

static int		ft_size_alloc(unsigned int nb)
{
	int		i;

	i = 1;
	if (nb > 0)
	{
		while ((nb / 10) > 0)
		{
			nb /= 10;
			i++;
		}
		return (i);
	}
	return (i);
}

static char		*ft_fill(char *ret, unsigned int nb, int div, int i)
{
	while (div > 0)
	{
		ret[i] = ((nb / div) + '0');
		nb -= (div * (nb / div));
		div /= 10;
		i++;
	}
	ret[i] = '\0';
	return (ret);
}

char			*ft_uitoa(unsigned int n)
{
	char			*ret;
	int				i;
	int				div;
	unsigned int	nb;

	i = 0;
	div = 0;
	nb = (unsigned int)n;
	ret = (char*)malloc(sizeof(*ret) * ft_size_alloc(nb) + 1);
	if (ret == NULL)
		return (NULL);
	div = ft_div(nb);
	ret = ft_fill(ret, nb, div, i);
	return (ret);
}
