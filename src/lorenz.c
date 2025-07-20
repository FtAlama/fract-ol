/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lorenz.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alama <alama@student.s19.be>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/15 18:13:55 by alama             #+#    #+#             */
/*   Updated: 2024/07/24 22:01:15 by alama            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static void	my_pixel_lorenz(int x, int y, t_img *img, int color)
{
	int	offset;

	if (x >= 0 && x < WIDTH_L && y >= 0 && y < HEIGHT_L)
	{
		offset = (y * img->line_len) + (x * (img->bpp / 8));
		*(unsigned int *)(img->pixels_ptr + offset) = color;
	}
}

static void	calcule_lorenz(t_complex *point, t_mlx *data)
{
	double		dt;
	t_complex	d_tmp;
	t_complex	tmp;	
	int			i;

	dt = 0.01;
	i = -1;
	tmp.y = 0;
	tmp.z = 0;
	tmp.x = 0.1;
	while (++i < data->frac.ite_def)
	{
		d_tmp.x = (A * (tmp.y - tmp.x)) * dt;
		d_tmp.y = (tmp.x * (B - tmp.z) - tmp.y) * dt;
		d_tmp.z = (tmp.x * tmp.y - C * tmp.z) * dt;
		tmp.x += d_tmp.x;
		tmp.y += d_tmp.y;
		tmp.z += d_tmp.z;
		point[i].x = tmp.x;
		point[i].y = tmp.y;
		point[i].z = tmp.z;
	}
}

static void	find_b(t_complex *p, int num_p, t_complex *min_b, t_complex *max_b)
{
	int	i;

	i = 0;
	min_b->x = 1e20;
	min_b->y = 1e20;
	min_b->z = 1e20;
	max_b->x = -1e20;
	max_b->y = -1e20;
	max_b->z = -1e20;
	while (i < num_p)
	{
		if (p[i].x < min_b->x)
			min_b->x = p[i].x;
		if (p[i].y < min_b->y)
			min_b->y = p[i].y;
		if (p[i].z < min_b->z)
			min_b->z = p[i].z;
		if (p[i].x > max_b->x)
			max_b->x = p[i].x;
		if (p[i].y > max_b->y)
			max_b->y = p[i].y;
		if (p[i].z > max_b->z)
			max_b->z = p[i].z;
		i++;
	}
}

static void	clear_image(t_img *img, int color)
{
	int	x;
	int	y;
	int	offset;

	y = 0;
	while (y < HEIGHT_L)
	{
		x = 0;
		while (x < WIDTH_L)
		{
			offset = (y * img->line_len) + (x * (img->bpp / 8));
			*(unsigned int *)(img->pixels_ptr + offset) = color;
			x++;
		}
		y++;
	}
}

void	lorenz_render(t_mlx *data)
{
	t_complex	*points;
	int			i;
	int			x;
	int			y;
	t_lorenz	lo;

	points = malloc(sizeof(t_complex) * data->frac.ite_def);
	clear_image(&data->img, WHITE);
	calcule_lorenz(points, data);
	find_b(points, data->frac.ite_def, &lo.min_bounds, &lo.max_bounds);
	step_up_lorenz(&lo, data);
	i = 0;
	x = 0;
	y = 0;
	while (i < data->frac.ite_def)
	{
		translate_point(&points[i], data->d.tx, data->d.ty, data->d.tz);
		rotate_point(&points[i], data->d.rx, data->d.ry);
		x = (int)(points[i].x * lo.scale + lo.offset_x);
		y = (int)(points[i].y * lo.scale + lo.offset_y);
		my_pixel_lorenz(x, y, &data->img, data->p[data->p3] + i);
		i++;
	}
	mlx_put_image_to_window(data->mlx, data->win, data->img.ptr_img, 0, 0);
	free(points);
}
