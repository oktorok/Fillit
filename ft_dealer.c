/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dealer.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jagarcia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/24 18:17:16 by jagarcia          #+#    #+#             */
/*   Updated: 2017/12/05 11:23:23 by jagarcia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

static void		cosa(int **aux_tetrim, int *aux, int **min)
{
	*aux_tetrim = aux + 1;
	while (**aux_tetrim >= 0)
	{
		if (!(*min) && (**aux_tetrim > *aux))
			*min = (*aux_tetrim);
		else if ((**aux_tetrim > *aux) && (**aux_tetrim < **min))
			*min = (*aux_tetrim);
		(*aux_tetrim)++;
	}
}

static int		update_aux_tetrim(int **aux_tetrim,
		unsigned char *sqr, unsigned int side, int *tetrim)
{
	int		*aux;
	int		*min;

	aux = *aux_tetrim;
	min = NULL;
	while (!min)
	{
		cosa(aux_tetrim, aux, &min);
		if (!min && *(aux - 1) < 0)
			return (0);
		else if (!min)
		{
			if (!(ft_erase(sqr, side, *(aux - 1), tetrim)))
				aux--;
			else
				break ;
		}
	}
	*aux_tetrim = aux;
	if (min)
	{
		ft_swap(min, *aux_tetrim);
		ft_sort_pos_int(*aux_tetrim + 1);
	}
	return (1);
}

void			ft_dealer(unsigned char *sqr,
		unsigned int side, int *tetrim, int **aux_tetrim)
{
	if (!(ft_fill(sqr, side, tetrim[**aux_tetrim], **aux_tetrim)))
	{
		if (!(*((*aux_tetrim) - 1) < 0))
		{
			if (ft_erase(sqr, side, *(--(*aux_tetrim)), tetrim))
				(*aux_tetrim)++;
			else if (!update_aux_tetrim(aux_tetrim, sqr, side, tetrim))
				**aux_tetrim = -1;
		}
		else
			(*aux_tetrim)--;
	}
	else
		(*aux_tetrim)++;
}
