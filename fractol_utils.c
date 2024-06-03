/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alama <alama@student.s19.be>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/03 15:26:41 by alama             #+#    #+#             */
/*   Updated: 2024/06/03 19:24:21 by alama            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	out_prog(t_data *data)
{
	mlx_destroy_image(data->mlx, data->img);
	mlx_clear_window(data->mlx, data->win);
	mlx_destroy_window(data->mlx, data->win);
	free(data->mlx);
	free(data);
	if (data->err_output == 0)
		exit(EXIT_SUCCESS);
	exit(EXIT_FAILURE);
	return (0);
}

int	key_event(int keycode, t_data *data)
{
	if (keycode == 53)
		out_prog(data);
	return (0);
}
