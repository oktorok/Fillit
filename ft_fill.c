/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fill.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrodrigu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/23 05:21:11 by mrodrigu          #+#    #+#             */
/*   Updated: 2017/12/05 11:20:11 by jagarcia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int			ft_fill(unsigned char *sqr, size_t side, int tet, unsigned int pos)
{
	size_t	i;
	int		*cod;
	size_t	j;

	i = 0;
	while (sqr[i])
	{
		if (sqr[i++] == '.')
		{
			cod = ft_decoder(side, tet, i - 1);
			j = 0;
			while (j < 4)
				if (cod[j++] >= (int)((side + 1) * side))
					return (0);
			if (sqr[cod[1]] == '.' && sqr[cod[2]] == '.' && sqr[cod[3]] == '.')
			{
				sqr[cod[0]] = 'A' + pos;
				sqr[cod[1]] = 'A' + pos;
				sqr[cod[2]] = 'A' + pos;
				sqr[cod[3]] = 'A' + pos;
				return (1);
			}
		}
	}
	return (0);
}
