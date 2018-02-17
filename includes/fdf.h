/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahouel <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/30 16:08:26 by ahouel            #+#    #+#             */
/*   Updated: 2017/04/20 16:01:48 by ahouel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H
# include <mlx.h>
# include <math.h>
# include "libft.h"

typedef struct	s_param
{
	void			*mlx;
	void			*win;
	void			*img;
	unsigned int	zoom;
	int				**imap;
	int				s_l;
	int				z_min;
	int				z_max;
	int				x_mod;
	int				y_mod;
	double			z_mod;
}				t_param;
typedef struct	s_line
{
	double		x1;
	double		y1;
	double		z1;
	double		x2;
	double		y2;
	double		z2;
}				t_line;
void			fdf_drawer(t_param *param);
char			*fdf_strjoin(char const *s1, char const *s2);
int				fdf(char *str);
int				fdf_map_maker(int **imap, int s_l, int s_c);
int				**fdf_imap_maker(char *map, int s_l, int s_c);
#endif
