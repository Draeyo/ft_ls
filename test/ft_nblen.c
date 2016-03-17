/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_nblen.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlistrat <vlistrat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/11 18:56:38 by vlistrat          #+#    #+#             */
/*   Updated: 2016/03/09 13:27:07 by vlistrat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

int		ft_nblen(int nb)
{
	int				i;
	unsigned int	n;

	i = 0;
	n = 0;
	if (nb < 0)
	{
		n *= -1;
		i++;
	}
	else if (nb == 0)
		return (1);
	n = (unsigned int)nb;
	while (nb)
	{
		nb /= 10;
		i++;
	}
	return (i);
}
