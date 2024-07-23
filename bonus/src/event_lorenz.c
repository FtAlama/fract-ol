/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   event_lorenz.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alama <alama@student.s19.be>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/23 18:07:08 by alama             #+#    #+#             */
/*   Updated: 2024/07/23 22:27:39 by alama            ###   ########.fr       */
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
				data->frac.ite_def += 50;
			}
			else if (data->d.ry > 50)
			{
				data->d.ry -= 0.1;
				data->d.ry -= 0.1;
				data->frac.ite_def -= 50;
			}
		}
		data->d.ry += 50;
	}
}

void	lorenz_key_event(int keycode, t_mlx *data)
{
	if (keycode == 123 || keycode == 0)
		data->d.tx -= 0.3;
	if (keycode == 124 || keycode == 2)
		data->d.tx += 0.3;
	if (keycode == 125 || keycode == 1)
		data->d.ty += 0.3;
	if (keycode == 126 || keycode == 13)
		data->d.ty -= 0.3;
	if (keycode == 69)
		data->frac.ite_def += 50;
	if (keycode == 78)
		if (data->frac.ite_def > 10)
			data->frac.ite_def -= 50;
	if (keycode == 31)
		data->d.ry += 0.1;
	if (keycode == 35)
		data->d.ry -= 0.1;
	if (keycode == 14)
		data->d.rx -= 0.2;
	if (keycode == 12)
		data->d.rx += 0.2;
	lorenz_danse(keycode, data);
}
