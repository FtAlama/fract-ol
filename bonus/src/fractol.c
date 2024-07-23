/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alama <alama@student.s19.be>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/24 12:03:54 by alama             #+#    #+#             */
/*   Updated: 2024/07/23 22:21:53 by alama            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	what_frac(t_complex *z, t_complex *c, t_mlx *data)
{
	if (data->nb_name == 1)
	{
		c->x = data->frac.julia_x;
		c->y = data->frac.julia_y;
	}
	else
	{
		c->x = z->x;
		c->y = z->y;
	}
}

static	void	ft_set_color(t_mlx *data)
{
	data->palette[0] = WHITE;
	data->palette[1] = BLACK;
	data->palette[2] = DRK_RED;
	data->palette[3] = SUN;
	data->palette[4] = BLUE_SKY;
	data->palette[5] = HOT_PINK;
	data->palette[6] = MINT_BLUE;
	data->palette[7] = COLOR_1;
	data->palette[8] = COLOR_2;
	data->palette[9] = COLOR_3;
	data->palette[10] = COLOR_3;
	data->palette[11] = COLOR_4;
	data->palette[12] = COLOR_5;
	data->palette[13] = COLOR_6;
	data->palette[14] = COLOR_7;
	data->p1 = 0;
	data->p2 = 0;
	data->p3 = 1;
}

static void	ft_set_lorenz(t_mlx *data)
{
	data->frac.ite_def = 100;
	data->d.rx = 0;
	data->d.ry = 0;
	data->d.tx = 0;
	data->d.tz = 0;
	data->d.ty = 0;
	lorenz_render(data);
}

void	frac_init(t_mlx *data)
{
	data->frac.escape_value = 4;
	data->frac.limit_x = 0.0;
	data->frac.limit_y = 0.0;
	data->frac.zoom = 1.0;
	if (data->frac.is_set == 0)
	{
		data->frac.julia_x = -0.8;
		data->frac.julia_y = 0.156;
	}
	ft_set_color(data);
	data->d.x = 0.01;
	data->d.y = 0;
	data->d.z = 0;
	if (data->nb_name == 2)
		ft_set_lorenz(data);
	else
	{
		data->frac.ite_def = 30;
		render(data);
	}
}
