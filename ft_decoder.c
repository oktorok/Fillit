/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_decoder.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrodrigu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/23 06:38:34 by mrodrigu          #+#    #+#             */
/*   Updated: 2017/12/05 11:14:35 by jagarcia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int		*ft_decoder(size_t side, int tet, int i)
{
	int *sqr_pos;

	sqr_pos = (int *)ft_memalloc(sizeof(int) * 4);
	sqr_pos[0] = i;
	if ((tet / 100) != 1)
		sqr_pos[1] = i + (tet / 100) + side - 4;
	else
		sqr_pos[1] = i + 1;
	if (((tet % 100) / 10) != 1)
		sqr_pos[2] = sqr_pos[1] + ((tet % 100) / 10) + side - 4;
	else
		sqr_pos[2] = sqr_pos[1] + 1;
	if ((tet % 10) != 1)
		sqr_pos[3] = sqr_pos[2] + (tet % 10) + side - 4;
	else
		sqr_pos[3] = sqr_pos[2] + 1;
	return (sqr_pos);
}
