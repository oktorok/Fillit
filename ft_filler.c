/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_filler.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrodrigu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/23 02:41:34 by mrodrigu          #+#    #+#             */
/*   Updated: 2017/12/05 11:27:06 by jagarcia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

static unsigned int			min_square(unsigned int *len_pos, int *tetrim)
{
	unsigned int		side;

	side = 2;
	while (tetrim[*len_pos])
		(*len_pos)++;
	while (*len_pos * 4 > side * side)
		side++;
	return (side);
}

static int					*memaux_tetrim(unsigned int len_tet, int **cosa)
{
	size_t	i;
	int		*aux_tetrim;

	i = 0;
	if (!(aux_tetrim = ft_memalloc(sizeof(int) * (len_tet + 2))))
		return (NULL);
	*cosa = aux_tetrim;
	aux_tetrim[0] = -1;
	aux_tetrim++;
	aux_tetrim[len_tet] = -2;
	while (i < len_tet)
	{
		aux_tetrim[i] = i;
		i++;
	}
	return (aux_tetrim);
}

static unsigned char		*memsqr(unsigned int side)
{
	unsigned char	*sqr;

	if (!(sqr = (unsigned char *)ft_memalloc(sizeof(char) *
					((side + 1) * side + 1))))
		return (NULL);
	sqr = (unsigned char *)ft_memset_fillit(sqr, (side + 1) * side, side);
	return (sqr);
}

unsigned char				*ft_filler(int *tetrim)
{
	unsigned int	len_tet;
	unsigned int	side;
	unsigned char	*sqr;
	int				*aux_tetrim;
	int				*head;

	len_tet = 0;
	head = NULL;
	side = min_square(&len_tet, tetrim);
	while (1)
	{
		aux_tetrim = head;
		if (aux_tetrim)
			free(aux_tetrim);
		aux_tetrim = memaux_tetrim(len_tet, &head);
		if (!(sqr = memsqr(side)))
			return (NULL);
		while (*aux_tetrim >= 0)
			ft_dealer(sqr, side, tetrim, &aux_tetrim);
		if (*aux_tetrim == -2)
			return (sqr);
		free(sqr);
		side++;
	}
	return (NULL);
}
