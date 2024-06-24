/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alama <alama@student.s19.be>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/24 12:03:54 by alama             #+#    #+#             */
/*   Updated: 2024/06/24 18:01:43 by alama            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	frac_init(t_mlx *data)
{
	data->frac.escape_value = 4;
	data->frac.ite_def = 50;
	data->frac.limit_x = 0.0;
	data->frac.limit_y = 0.0;
	data->frac.zoom = 1.0;
	render(data);
}
