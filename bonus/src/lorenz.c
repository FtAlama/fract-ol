/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lorenz.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alama <alama@student.s19.be>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/15 18:13:55 by alama             #+#    #+#             */
/*   Updated: 2024/07/22 20:26:29 by alama            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static void	my_pixel_lorenz(int x, int y, t_img *img, int color, int i)
{
	int	offset;

	if (x >= 0 && x < WIDTH && y >= 0 && y < HEIGHT)
	{
		offset = (y * img->line_len) + (x * (img->bpp / 8));
		*(unsigned int *)(img->pixels_ptr + offset) = color + i;
	}
}

static void calcule_lorenz(t_dpp *point, t_mlx *data)
{
	double	dt;
	double	dx;
	double	dy;
	double	dz;
	double	x;
	double	y;
	double	z;
	int		i;

	dt = 0.01;
	i = 0;
	y = 0;
	z = 0;
	x = 0.1;
	while (i < data->frac.ite_def)
	{
		dx = (A * (y - x)) * dt;
		dy = (x * (B - z) - y) * dt;
		dz = (x * y - C * z) * dt;
		x += dx;
		y += dy;
		z += dz;
		point[i].x = x;
		point[i].y = y;
		point[i].z = z;
		i++;
	}
}

static void	find_bounds(t_dpp *points, int num_points, t_dpp *min_bounds, t_dpp *max_bounds)
{
	int	i;

	i = 0;
	min_bounds->x = 1e20;
	min_bounds->y = 1e20;
	min_bounds->z = 1e20;
	max_bounds->x = -1e20;
	max_bounds->y = -1e20;
	max_bounds->z = -1e20;
	while (i < num_points)
	{
		if (points[i].x < min_bounds->x)
			min_bounds->x = points[i].x;
		if (points[i].y < min_bounds->y)
			min_bounds->y = points[i].y;
		if (points[i].z < min_bounds->z)
			min_bounds->z = points[i].z;
		if (points[i].x > max_bounds->x)
			max_bounds->x = points[i].x;
		if (points[i].y > max_bounds->y)
			max_bounds->y = points[i].y;
		if (points[i].z > max_bounds->z)
			max_bounds->z = points[i].z;
		i++;
	}
}

static void	clear_image(t_img *img, int color)
{
	int	x;
	int	y;
	int	offset;

	y = 0;
	while (y < HEIGHT)
	{
		x = 0;
		while (x < WIDTH)
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
	t_dpp	points[data->frac.ite_def];
	double	angle_x;
	double	angle_y;
	int		i;
	int		x;
	int		y;
	double	scale_x;
	double	scale_y;
	double	scale;
	t_dpp	min_bounds;
	t_dpp	max_bounds;
	double	offset_x;
	double	offset_y;

	clear_image(&data->img, WHITE);
	calcule_lorenz(points, data);
	find_bounds(points, data->frac.ite_def, &min_bounds, &max_bounds);
	scale_x = (WIDTH / (max_bounds.x - min_bounds.x)) * data->frac.zoom;
	scale_y = (HEIGHT / (max_bounds.y - min_bounds.y)) * data->frac.zoom;
	if (scale_x < scale_y)
		scale = scale_x;
	else
		scale = scale_y;
	offset_x = (WIDTH - (max_bounds.x - min_bounds.x) * scale) / 2.0 - min_bounds.x * scale;
	offset_y = (HEIGHT - (max_bounds.y - min_bounds.y) * scale) / 2.0 - min_bounds.y * scale;
	i = 0;
	x = 0;
	y = 0;
	angle_x = M_PI / 4;
	angle_y = M_PI / 4;
	while (i < data->frac.ite_def)
	{
		x = (int)(points[i].x * scale + offset_x);
		y = (int)(points[i].y * scale + offset_y);
		my_pixel_lorenz(x, y, &data->img, data->palette[data->p3], i);
		i++;
	}
	mlx_put_image_to_window(data->mlx, data->win, data->img.ptr_img, 0, 0);
}
