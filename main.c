/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jagarcia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/24 19:08:50 by jagarcia          #+#    #+#             */
/*   Updated: 2017/12/05 11:17:00 by jagarcia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int	main(int argc, const char **argv)
{
	int *pos;

	(void)argc;
	if (argc != 2)
	{
		ft_putstr("usage: ./fillit sample.fillit\n");
		return (0);
	}
	pos = ft_reader(argv[1]);
	if (pos)
		ft_putstr((const char *)ft_filler(pos));
	else
		ft_putstr("error\n");
	return (0);
}
