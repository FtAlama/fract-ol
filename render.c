/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alama <alama@student.s19.be>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/13 20:15:58 by alama             #+#    #+#             */
/*   Updated: 2024/06/17 17:24:28 by alama            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static void	my_pixel_put(int x, int y, t_img *img, int color)
{
	int	offset;

	offset = (y * img->line_len) + (x * (img->bits_pp / 8));
	*(unsigned int *)(img->pixels_ptr + offset) = color;
}

void	handle_pixel(int x, int y, t_fract *frac)
{
	t_complex	z;
	t_complex	c;
	int			i;
	int			color;

	z.real = 0.0;
	z.ima = 0.0;
	i = 0;
	c.real = scale(x, -2, 2, WIDTH) + frac->limit.x;
	c.ima = scale(y, 2, -2, HEIGHT) + frac->limit.y;
	while (i < frac->iterations_definition)
	{
		z = sum_complex(square_complex(z), c);
		if ((z.real * z.real) + (z.ima * z.ima) > frac->escape_value)
		{
			color = scale(i, BLACK, WHITE, frac->iterations_definition);
			my_pixel_put(x, y, &frac->img, color);
			return ;
		}
		i++;
	}
	my_pixel_put(x, y, &frac->img, BLUE_SKY);
}

void	render(t_fract *frac)
{
	int	x;
	int	y;

	y = 0;
	while (y < HEIGHT)
	{
		x = 0;
		while (x < WIDTH)
		{
			handle_pixel(x, y, frac);
			x++;
		}
		y++;
	}
	mlx_put_image_to_window(frac->mlx, frac->win, frac->img.ptr_img, 0, 0);
}
