/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrodrigu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/21 02:19:55 by mrodrigu          #+#    #+#             */
/*   Updated: 2017/12/05 11:26:23 by jagarcia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLIT_H
# define FILLIT_H
# include <fcntl.h>
# include "libft.h"

static const unsigned int g_tetriminos[19] = {555, 111, 141, 411, 514, 114,
	415, 131, 515, 151, 414, 511, 145, 115, 541, 311, 551, 113, 155};

int				*ft_reader(const char *src);
int				ft_check(char *a);
unsigned char	*ft_filler(int *tetrim);
int				ft_fill(unsigned char *s, size_t d, int t, unsigned int pos);
int				ft_erase(unsigned char *sqr, unsigned int side,
		unsigned int pos, int *tetrim);
int				*ft_decoder(size_t side, int tet, int i);
void			*ft_memset_fillit(void *dest, size_t n, size_t size);
void			ft_dealer(unsigned char *sqr,
		unsigned int side, int *tetrim, int **aux_tetrim);
#endif
