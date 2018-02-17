/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_imap.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahouel <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/31 17:49:19 by ahouel            #+#    #+#             */
/*   Updated: 2017/04/20 14:17:20 by ahouel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static int	**init_imap(int **imap, int s_l, int s_c)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (i < s_c)
	{
		j = 0;
		while (j < s_l)
			imap[i][j++] = 0;
		++i;
	}
	return (imap);
}

static int	**imap_alloc(int s_l, int s_c)
{
	int	**imap;
	int	i;

	i = 0;
	imap = NULL;
	if (!(imap = (int**)malloc(sizeof(int*) * s_c + 1)))
		return (NULL);
	while (i < s_c)
		if (!(imap[i++] = (int*)malloc(sizeof(int) * s_l)))
		{
			while (--i > -1)
				free(imap[i]);
			free(imap);
			return (NULL);
		}
	imap[i] = NULL;
	return (imap);
}

static int	**fill_imap(int **imap, char *map, int s_l)
{
	int	i;
	int	x;
	int	y;

	i = 0;
	x = 0;
	y = 0;
	while (map[i])
	{
		if ((map[i] > 47 && map[i] < 58) || map[i] == '-' || map[i] == '+')
		{
			imap[y][x++] = ft_atoi(map + i);
			if (x >= s_l)
			{
				x = 0;
				++y;
			}
			while ((map[i] > 47 && map[i] < 58) || map[i] == '-'
					|| map[i] == '+')
				++i;
		}
		else
			++i;
	}
	return (imap);
}

int			**fdf_imap_maker(char *map, int s_l, int s_c)
{
	int	**imap;

	if (!(map))
		return (NULL);
	if (!(imap = imap_alloc(s_l, s_c)))
		return (NULL);
	if (!(imap = init_imap(imap, s_l, s_c)))
		return (NULL);
	if (!(imap = fill_imap(imap, map, s_l)))
		return (NULL);
	return (imap);
}
