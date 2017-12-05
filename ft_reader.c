/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_reader.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrodrigu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/22 07:45:04 by mrodrigu          #+#    #+#             */
/*   Updated: 2017/12/05 11:29:22 by jagarcia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

static int			*reall(int *terms, int new)
{
	unsigned int	len;
	int				*new_ter;

	if (!new)
		return (NULL);
	if (terms)
	{
		len = 0;
		while (terms[len])
			len++;
		if (!(new_ter = (int *)ft_memalloc(sizeof(int) * (len + 2))))
			return (NULL);
		new_ter[len] = new;
		while (--len != 0)
			new_ter[len] = terms[len];
		new_ter[0] = terms[0];
		free(terms);
	}
	else
	{
		if (!(new_ter = (int *)ft_memalloc(sizeof(int) * 2)))
			return (NULL);
		new_ter[0] = new;
	}
	return (new_ter);
}

static int			manager(int fd, int **terms, int *bool)
{
	char			datos[21];
	int				rd;

	rd = read(fd, datos, 21);
	while (rd)
	{
		if ((datos[20] != '\n' && rd == 21) || rd < 0)
			return (0);
		if (rd == 20)
			*bool = 0;
		else if (rd < 20)
			return (0);
		if (!(*terms = reall(*terms, ft_check(datos))))
			return (0);
		ft_memset(datos, 0, 21);
		rd = read(fd, datos, 21);
	}
	return (1);
}

int					*ft_reader(const char *src)
{
	int			fd;
	int			*terms;
	int			bool;

	bool = 1;
	terms = NULL;
	fd = open(src, O_RDONLY);
	if (fd < 0)
		return (0);
	if (!(manager(fd, &terms, &bool)))
		return (0);
	if (bool)
		return (0);
	close(fd);
	return (terms);
}
