/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrodrigu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/09 21:40:06 by mrodrigu          #+#    #+#             */
/*   Updated: 2017/11/24 17:01:42 by jagarcia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

void	*ft_memset_fillit(void *dest, size_t n, size_t size)
{
	size_t			i;
	unsigned char	*aux;

	aux = (unsigned char *)dest;
	i = 0;
	while (i < n)
	{
		if (!((i + 1) % (size + 1)))
			aux[i++] = '\n';
		else
			aux[i++] = '.';
	}
	return (dest);
}
