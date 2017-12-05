/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_erase.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrodrigu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/23 06:41:36 by mrodrigu          #+#    #+#             */
/*   Updated: 2017/12/05 11:18:48 by jagarcia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int	ft_erase(unsigned char *sqr, unsigned int side,
		unsigned int pos, int *tetrim)
{
	size_t			i;
	size_t			j;
	unsigned int	c;

	c = 0;
	i = 0;
	j = 0;
	while (sqr[i] && c < 4)
	{
		if (sqr[i] == ('A' + pos))
		{
			sqr[i] = '.';
			c++;
			i++;
			if (!j)
				j = i;
		}
		else
			i++;
	}
	if (!ft_fill(&(sqr[j + 1]), side, tetrim[pos], pos))
		return (0);
	return (666);
}
