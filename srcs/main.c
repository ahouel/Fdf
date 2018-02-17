/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahouel <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/31 16:22:50 by ahouel            #+#    #+#             */
/*   Updated: 2017/04/20 14:18:55 by ahouel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	main(int ac, char **av)
{
	int	ret;

	ret = 0;
	if (ac != 2)
	{
		ft_printf("Usage : ./fdf <filename>\n");
		return (-1);
	}
	ret = fdf(av[1]);
	if (ret == -1)
		ft_printf("Failed to read the file <%s>\n", av[1]);
	if (ret == -2)
		ft_printf("File <%s> is too small\n", av[1]);
	if (ret == -4)
		ft_printf("Map in file <%s> isn't a rectangle\n", av[1]);
	if (ret == -5)
		ft_printf("File <%s> has a wrong format\n", av[1]);
	if (ret == -10)
		ft_printf("The structure in <%s> is too big\n", av[1]);
	return (ret);
}
