/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   zoom.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alama <alama@student.s19.be>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/28 19:40:30 by alama             #+#    #+#             */
/*   Updated: 2024/07/13 21:31:27 by alama            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	zoom_in(t_mlx *data, double zoom_factor, int x, int y)
{
	double	ratio;
	double	lx;
	double	ly;

	ratio = (double)WIDTH / HEIGHT;
	lx = (map(x, -2 * ratio, 2 * ratio, WIDTH) * data->frac.zoom);
	data->frac.limit_x += lx;
	ly = (map(y, 2, -2, HEIGHT) * data->frac.zoom);
	data->frac.limit_y += ly;;
	data->frac.zoom /= zoom_factor;
	render(data);
}
