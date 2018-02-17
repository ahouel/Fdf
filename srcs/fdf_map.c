/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_map.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahouel <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/31 18:22:20 by ahouel            #+#    #+#             */
/*   Updated: 2017/04/20 15:53:57 by ahouel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static void	commands_key2(int keycode, t_param *para)
{
	if (keycode == 124)
	{
		para->x_mod += 10;
		ft_printf("Move right\n");
	}
	else if (keycode == 123)
	{
		para->x_mod -= 10;
		ft_printf("Move left\n");
	}
	else if (keycode == 82)
	{
		para->z_mod -= 0.1;
		ft_printf("Reduce height\n");
	}
	else if (keycode == 65)
	{
		para->z_mod += 0.1;
		ft_printf("Add height\n");
	}
	else
		ft_printf("Entered keycode : %d, no usage\n", keycode);
}

static void	commands_key1(int keycode, t_param *para)
{
	if (keycode == 78 && para->zoom > 5)
	{
		para->zoom -= 3;
		ft_printf("Zoom -\n");
	}
	else if (keycode == 69 && para->zoom < 60)
	{
		para->zoom += 3;
		ft_printf("Zoom +\n");
	}
	else if (keycode == 125)
	{
		para->y_mod += 10;
		ft_printf("Move down\n");
	}
	else if (keycode == 126)
	{
		para->y_mod -= 10;
		ft_printf("Move up\n");
	}
	else
		commands_key2(keycode, para);
}

static int	my_key_fun(int keycode, void *param)
{
	t_param	*para;
	int		y;

	para = (t_param*)param;
	y = -1;
	if (keycode == 53)
	{
		while (para->imap[++y] != NULL)
			free(para->imap[y]);
		free(para->imap[y]);
		free(para->imap);
		ft_printf("Exit process\n");
		exit(EXIT_SUCCESS);
	}
	else
	{
		mlx_clear_window(para->mlx, para->win);
		commands_key1(keycode, para);
		fdf_drawer(para);
	}
	return (0);
}

static void	param_init(t_param *param, int **imap, int s_l)
{
	int	x;
	int	y;

	x = 0;
	y = 0;
	param->z_mod = 1;
	param->zoom = 19;
	param->imap = imap;
	param->s_l = s_l;
	param->z_min = 0;
	param->z_max = 0;
	while (imap[y] != NULL)
	{
		x = -1;
		while (++x < param->s_l)
		{
			imap[y][x] > param->z_max ? (param->z_max = imap[y][x]) : 0;
			imap[y][x] < param->z_min ? (param->z_min = imap[y][x]) : 0;
		}
		++y;
	}
}

int			fdf_map_maker(int **imap, int s_l, int s_c)
{
	t_param	param;
	int		x;
	int		y;

	x = 3000;
	y = 3000;
	param_init(&param, imap, s_l);
	while ((x > 2000 || y > 2000) && --param.zoom > 5)
	{
		x = sqrt((s_l * s_l) + (s_c * s_c)) * param.zoom + 100;
		y = ((sqrt((s_l * s_l) + (s_c * s_c))) + (param.z_max - param.z_min))
			* param.zoom + 100;
	}
	param.x_mod = x / 2;
	param.y_mod = y / 2;
	(param.z_max == param.z_min) ? param.z_max++ : 0;
	ft_printf("Window weidth : %d\nWindow height : %d\n", x, y);
	if (param.zoom <= 5)
		return (-10);
	param.mlx = mlx_init();
	param.win = mlx_new_window(param.mlx, x, y, "Fdf");
	mlx_key_hook(param.win, my_key_fun, (void*)&param);
	fdf_drawer(&param);
	mlx_loop(param.mlx);
	return (0);
}
