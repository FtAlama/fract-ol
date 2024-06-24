/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alama <alama@student.s19.be>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/24 14:01:15 by alama             #+#    #+#             */
/*   Updated: 2024/06/24 18:57:59 by alama            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static void my_pixel_put(int x, int y, t_img *img, int color)
{
	int	offset;

	offset = (y * img->line_len) + (x * (img->bpp / 8));
	*(unsigned int *)(img->pixels_ptr + offset) = color;
}

static void	handle_pixel(int x, int y, t_frac *frac)
{
	t_complex	z;
	t_complex	c;
	int			i;
	int			color;
}

void	render(t_mlx *data)
{
	int	x;
	int	y;

	x = 0;}
	while (y < HEIGHT)
	{
		x = 0;
		while (x < WIDTH)
		{
			handle_pixel(x, y, &data->frac);
			x++;
		}
		y++;
	}
	mlx_put_image_to_window(data->mlx, data->win, data->img.ptr_img, 0, 0);
}
