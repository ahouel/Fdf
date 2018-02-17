/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_drawer.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahouel <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/20 14:19:13 by ahouel            #+#    #+#             */
/*   Updated: 2017/04/20 15:54:00 by ahouel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static void	draw_line(t_param *param, t_line *line)
{
	double	ty;
	double	tx;
	double	tmp;
	double	tz;

	tz = line->z2 - line->z1;
	ty = line->y2 - line->y1;
	tx = line->x2 - line->x1;
	tmp = sqrt((tx * tx) + (ty * ty));
	ty /= tmp;
	tx /= tmp;
	tz /= tmp;
	while (tmp > 0)
	{
		mlx_pixel_put(param->mlx, param->win, line->x1 + param->x_mod, line->y1
				+ param->y_mod, (0x00FFFFFF - (((line->z1 - param->z_min *
				param->z_mod) * 0x000000FF) /
				((param->z_max - param->z_min) * param->z_mod))));
		line->x1 += tx;
		line->y1 += ty;
		line->z1 += tz;
		tmp--;
	}
}

static void	c_lines(t_param *param, t_line *line)
{
	int	x;
	int	y;

	y = 0;
	while (param->imap[y + 1] != NULL)
	{
		x = 0;
		while (x < param->s_l)
		{
			line->x1 = ((sqrt(2) / 2) * (x - y)) * param->zoom;
			line->y1 = ((1 / sqrt(6)) * (x + y) - (0.82 * (param->imap[y][x] *
							param->z_mod))) * param->zoom;
			line->z1 = param->imap[y][x] * param->z_mod;
			line->x2 = ((sqrt(2) / 2) * (x - (y + 1))) * param->zoom;
			line->y2 = (((1 / sqrt(6)) * (x + y + 1)) - (0.82 *
						(param->imap[y + 1][x] * param->z_mod))) * param->zoom;
			line->z2 = param->imap[y + 1][x] * param->z_mod;
			draw_line(param, line);
			++x;
		}
		++y;
	}
}

static void	l_lines(t_param *param, t_line *line)
{
	int	x;
	int	y;

	y = 0;
	while (param->imap[y] != NULL)
	{
		x = 0;
		while (x < param->s_l - 1)
		{
			line->x1 = ((sqrt(2) / 2) * (x - y)) * param->zoom;
			line->y1 = ((1 / sqrt(6)) * (x + y) - (0.82 * (param->imap[y][x] *
							param->z_mod))) * param->zoom;
			line->z1 = param->imap[y][x] * param->z_mod;
			++x;
			line->x2 = ((sqrt(2) / 2) * (x - y)) * param->zoom;
			line->y2 = ((1 / sqrt(6)) * (x + y) - (0.82 * (param->imap[y][x] *
							param->z_mod))) * param->zoom;
			line->z2 = param->imap[y][x] * param->z_mod;
			draw_line(param, line);
		}
		++y;
	}
}

void		fdf_drawer(t_param *param)
{
	t_line	line;

	l_lines(param, &line);
	c_lines(param, &line);
}
