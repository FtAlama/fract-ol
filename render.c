/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alama <alama@student.s19.be>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/13 20:15:58 by alama             #+#    #+#             */
/*   Updated: 2024/06/19 23:21:15 by alama            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static void	my_pixel_put(int x, int y, t_img *img, int color)
{
	int	offset;

	offset = (y * img->line_len) + (x * (img->bits_pp / 8));
	*(unsigned int *)(img->pixels_ptr + offset) = color;
}

static	void mandel_or_julia(t_complex *z, t_complex *c, t_fract *frac)
{
	if (!ft_strncmp(frac->name, "julia", 5))
	{
		c->real = frac->julia_x;
		c->ima = frac->julia_y;
	}
	else
	{
		c->real = z->real;
		c->ima = z->ima;
	}
}

void	handle_pixel(int x, int y, t_fract *frac)
{
	t_complex	z;
	t_complex	c;
	int			i;
	int			color;

	i = 0;
	z.real = (scale(x, -2, 2, WIDTH) * frac->zoom) + frac->limit.x;
	z.ima = (scale(y, 2, -2, HEIGHT) * frac->zoom) + frac->limit.y;
	mandel_or_julia(&z, &c, frac);
	while (i < frac->iterations_definition && (x < WIDTH && y < HEIGHT))
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
