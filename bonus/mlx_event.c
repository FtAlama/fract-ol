/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_event.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alama <alama@student.s19.be>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/24 11:13:22 by alama             #+#    #+#             */
/*   Updated: 2024/06/24 11:55:01 by alama            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	out_prog(t_mlx *data)
{
	if (data->img.ptr_img)
		mlx_destroy_image(data->mlx, data->img.ptr_img);
	if (data->win)
		mlx_clear_window(data->mlx, data->win);
	if (data->mlx)
	{
		mlx_destroy_window(data->mlx, data->win);
		free(data->mlx);
	}
	if (data->err_out == 0)
	{
		ft_printf("success close\n");
		exit(EXIT_SUCCESS);
	}
	else if (data->err_out == 1)
		perror("...Malloc allocation failed...\n");
	exit(EXIT_FAILURE);
	return (0);
}

static int	key_event(int keycode, t_mlx *data)
{
	if (keycode == 53)
		out_prog(data);
	return (0);
}

void	events_init(t_mlx *data)
{
	mlx_hook(data->win, 2, 0, &key_event, data);
	mlx_hook(data->win, 17, 0, &out_prog, data);
}
