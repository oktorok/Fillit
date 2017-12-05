/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cheker.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrodrigu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/22 07:39:09 by mrodrigu          #+#    #+#             */
/*   Updated: 2017/12/05 11:13:42 by jagarcia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int		ft_check(char *datos)
{
	unsigned int pos[4];
	unsigned int i;
	unsigned int n;

	i = 0;
	n = 0;
	while (i < 20)
	{
		if (!((i + 1) % 5) && datos[i] != '\n')
			return (0);
		if ((((i + 1) % 5) > 0) && (datos[i] != '.' && datos[i] != '#'))
			return (0);
		if (datos[i] == '#' && n <= 3)
			pos[n++] = i + 1;
		else if (datos[i] == '#' && n > 3)
			return (0);
		i++;
	}
	i = 0;
	n = (((pos[1] - pos[0]) * 100) + ((pos[2] - pos[1]) *
				10) + (pos[3] - pos[2]));
	while (i < 19)
		if (!(n - g_tetriminos[i++]))
			return (n);
	return (0);
}
