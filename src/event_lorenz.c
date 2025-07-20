/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   event_lorenz.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alama <alama@student.s19.be>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/23 18:07:08 by alama             #+#    #+#             */
/*   Updated: 2024/07/24 22:09:51 by alama            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static void	lorenz_danse(int keycode, t_mlx *data)
{
	if (keycode == 38)
	{
		if (data->d.ry < 15000)
		{
			if (data->d.ry < 15000)
			{
				data->d.ry -= 0.1;
				data->d.rx -= 0.1;
				data->frac.ite_def += 20;
			}
			else if (data->d.ry > 50)
			{
				data->d.ry -= 0.1;
				data->d.ry -= 0.1;
				data->frac.ite_def -= 20;
			}
		}
		data->d.ry += 50;
	}
}

void	lorenz_key_event(int keycode, t_mlx *data)
{
	if (keycode == 123 || keycode == 0)
		data->d.tx -= 0.5;
	if (keycode == 124 || keycode == 2)
		data->d.tx += 0.5;
	if (keycode == 125 || keycode == 1)
		data->d.ty += 0.5;
	if (keycode == 126 || keycode == 13)
		data->d.ty -= 0.5;
	if (keycode == 69)
		data->frac.ite_def += 50;
	if (keycode == 78)
		if (data->frac.ite_def > 10)
			data->frac.ite_def -= 50;
	if (keycode == 31)
		data->d.ry += 0.2;
	if (keycode == 35)
		data->d.ry -= 0.2;
	if (keycode == 14)
		data->d.rx -= 0.2;
	if (keycode == 12)
		data->d.rx += 0.2;
	lorenz_danse(keycode, data);
}

void	step_up_lorenz(t_lorenz *lo, t_mlx *data)
{
	lo->scale_x = WIDTH_L / (lo->max_bounds.x - lo->min_bounds.x);
	lo->scale_x *= data->frac.zoom;
	lo->scale_y = HEIGHT_L / (lo->max_bounds.y - lo->min_bounds.y);
	lo->scale_y *= data->frac.zoom;
	if (lo->scale_x < lo->scale_y)
		lo->scale = lo->scale_x;
	else
		lo->scale = lo->scale_y;
	lo->offset_x = WIDTH_L - (lo->max_bounds.x - lo->min_bounds.x) * lo->scale;
	lo->offset_x = lo->offset_x / 2.0 - lo->min_bounds.x * lo->scale;
	lo->offset_y = HEIGHT_L - (lo->max_bounds.y - lo->min_bounds.y) * lo->scale;
	lo->offset_y = lo->offset_y / 2.0 - lo->min_bounds.y * lo->scale;
}
