/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahouel <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/31 16:31:04 by ahouel            #+#    #+#             */
/*   Updated: 2017/04/20 13:55:38 by ahouel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static char	*reader(char *str)
{
	char	*map;
	char	*tmp;
	char	*ptr;
	int		i;
	int		fd;

	map = NULL;
	tmp = NULL;
	ptr = NULL;
	i = 0;
	if ((fd = open(str, O_RDONLY)) < 0)
		return (NULL);
	if (!(map = ft_strnew(0)))
		return (NULL);
	while (get_next_line(fd, &tmp) > 0)
	{
		ptr = map;
		map = fdf_strjoin(map, tmp);
		free(tmp);
		free(ptr);
	}
	return (map);
}

static void	fdf_sizes(char *map, int *s_l, int *s_c)
{
	int	i;

	i = 0;
	while (map[i] && map[i] != '\n')
	{
		if (map[i] > 47 && map[i] < 58)
		{
			++(*s_l);
			while (map[i] > 47 && map[i] < 58)
				++i;
		}
		else
			++i;
	}
	i = -1;
	while (map[++i])
	{
		if (map[i] == '\n')
			(*s_c)++;
	}
}

static int	fdf_error2(char *map, int *s_l, int *s_c)
{
	int	i;

	i = -1;
	if (*s_l == 0 || (*s_l == 1 && *s_c == 1))
		return (-2);
	while (map[++i + 1])
	{
		if ((map[i] < 48 && map[i] > 57 && map[i] != ' '
				&& map[i] != '+' && map[i] != '-') || ((map[i] == '-' ||
				map[i] == '+') && map[i + 1] > 47 && map[i + 1] < 58))
			return (-5);
	}
	return (0);
}

static int	fdf_error1(char *map, int *s_l, int *s_c)
{
	int	i;
	int	x;

	i = -1;
	x = 0;
	if (!map || !(*map))
		return (-2);
	while (map[++i])
	{
		if (map[i] > 47 && map[i] < 58)
		{
			++x;
			while (map[i] > 47 && map[i] < 58)
				++i;
			if (map[i] != ' ' && map[i] != '\n')
				return (-5);
		}
		if (map[i] == '\n')
		{
			if (x != *s_l)
				return (-4);
			x = 0;
		}
	}
	return (fdf_error2(map, s_l, s_c));
}

int			fdf(char *str)
{
	int		**imap;
	char	*map;
	int		ret;
	int		s_l;
	int		s_c;

	s_l = 0;
	s_c = 0;
	imap = NULL;
	map = NULL;
	ret = 0;
	if (!(map = reader(str)))
		return (-1);
	ft_printf("\nMap :\n%s------\n", map);
	fdf_sizes(map, &s_l, &s_c);
	if ((ret = fdf_error1(map, &s_l, &s_c)) < 0)
		return (ret);
	ft_printf("Size of a line : %d\nSize of a column : %d\n", s_l, s_c);
	if (!(imap = fdf_imap_maker(map, s_l, s_c)))
		return (ret);
	ret = fdf_map_maker(imap, s_l, s_c);
	return (ret);
}
