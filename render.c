/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alama <alama@student.s19.be>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/13 20:15:58 by alama             #+#    #+#             */
/*   Updated: 2024/06/24 19:11:26 by alama            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static void	my_pixel_put(int x, int y, t_img *img, int color)
{
	int	offset;

	offset = (y * img->line_len) + (x * (img->bits_pp / 8));
	*(unsigned int *)(img->pixels_ptr + offset) = color;
}

/**
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
*/
void	handle_pixel(int x, int y, t_fract *frac)
{
	/**
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
	*/
    t_complex z;
    t_complex c;
    int i;
    int color;
    double z_real_squared;
    double z_ima_squared;

    z.real = 0.0;
    z.ima = 0.0;
    i = 0;
    c.real = (scale(x, -2, 2, WIDTH) * frac->zoom) + frac->limit.x;
    c.ima = (scale(y, 2, -2, HEIGHT) * frac->zoom) + frac->limit.y;

    while (i < frac->iterations_definition) {
        z_real_squared = z.real * z.real;
        z_ima_squared = z.ima * z.ima;

        if (z_real_squared + z_ima_squared > frac->escape_value) {
            color = scale(i, BLACK, WHITE, frac->iterations_definition);
            my_pixel_put(x, y, &frac->img, color);
            return;
        }

        z.ima = 2 * z.real * z.ima + c.ima;
       z.real = z_real_squared - z_ima_squared + c.real;

        i++;
    }

    my_pixel_put(x, y, &frac->img, BLUE_SKY);
}

void	render(t_fract *frac)
{
	render_region(frac, 0, 0, WIDTH, HEIGHT);
	/*
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
	*/
}

void	zoom_in(t_fract *frac, double zoom_factor, int x, int y)
{
	double	new_zoom;
	double	offset_x;
	double	offset_y;

	new_zoom = frac->zoom * zoom_factor;
	offset_x = (x - (WIDTH / 2)) / (WIDTH / 2);
	offset_y = (y - (HEIGHT / 2)) / (HEIGHT / 2);
	frac->limit.x += offset_x * frac->zoom;
	frac->limit.y += offset_y * frac->zoom;
	frac->zoom = new_zoom;
}

void	render_region(t_fract *frac, int start_x, int start_y, int end_x, int end_y)
{
	int	x;
	int	y;

	y = start_y;
	while (y < end_y)
	{
		x = start_x;
		while (x < end_x)
		{
			handle_pixel(x, y, frac);
			x++;
		}
		y++;
	}
	mlx_put_image_to_window(frac->mlx, frac->win, frac->img.ptr_img, 0, 0);
}

void	zoom_and_render(t_fract *frac, double zoom_factor, int x, int y)
{
	int	cap;

	cap = frac->iterations_definition;
	frac->iterations_definition = 50;
	zoom_in(frac, zoom_factor, x, y);
	render_region(frac, 0, 0, WIDTH, HEIGHT);
	frac->iterations_definition = cap;
	render_region(frac, 0, 0, WIDTH, HEIGHT);
}
