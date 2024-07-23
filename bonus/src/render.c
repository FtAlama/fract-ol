/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alama <alama@student.s19.be>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/24 14:01:15 by alama             #+#    #+#             */
/*   Updated: 2024/07/23 22:32:24 by alama            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static void	my_pixel_put(int x, int y, t_img *img, int color)
{
	int	offset;

	offset = (y * img->line_len) + (x * (img->bpp / 8));
	*(unsigned int *)(img->pixels_ptr + offset) = color;
}

static void	handle_pixel(int x, int y, t_mlx *data)
{
	t_complex	z;
	t_complex	c;
	int			i;
	int			color;
	t_complex	tmp;

	tmp.x = (double)WIDTH / HEIGHT;
	i = 0;
	z.x = map(x, -2 * tmp.x, 2 * tmp.x, WIDTH) * data->frac.zoom;
	z.x += data->frac.limit_x;
	z.y = (map(y, 2, -2, HEIGHT) * data->frac.zoom) + data->frac.limit_y;
	what_frac(&z, &c, data);
	while (i++ < data->frac.ite_def)
	{
		tmp.y = z.x * z.x - z.y * z.y + c.x;
		z.y = 2 * z.x * z.y + c.y;
		z.x = tmp.y;
		if ((z.x * z.x) + (z.y * z.y) > data->frac.escape_value)
		{
			color = map(i, data->palette[data->p1], data->palette[data->p2], data->frac.ite_def);
			my_pixel_put(x, y, &data->img, color);
			return ;
		}
	}
	my_pixel_put(x, y, &data->img, data->palette[data->p3]);
}

void	render(t_mlx *data)
{
	int	x;
	int	y;

	if (data->nb_name == 2)
		lorenz_render(data);
	else
	{
		y = 0;
		while (y < HEIGHT)
		{
			x = 0;
			while (x < WIDTH)
			{
				handle_pixel(x, y, data);
				x++;
			}
			y++;
		}
		mlx_put_image_to_window(data->mlx, data->win, data->img.ptr_img, 0, 0);
	}
}
