/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_event.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alama <alama@student.s19.be>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/24 11:13:22 by alama             #+#    #+#             */
/*   Updated: 2024/07/20 20:14:28 by alama            ###   ########.fr       */
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

static void	key_color(int keycode, t_mlx *data)
{
	if (keycode == 8)
	{
		if (data->p1 == data->p2 || data->p3 == data->p1)
			data->p1++;
		data->p1++;
	}
	if (keycode == 9)
	{
		if (data->p1 == data->p2 || data->p3 == data->p2)
			data->p2++;
		data->p2++;
	}
	if (keycode == 11)
	{
		if (data->p1 == data->p3 || data->p3 == data->p1)
			data->p3++;
		data->p3++;
	}
}

static int	key_event(int keycode, t_mlx *data)
{
	ft_printf("%d\n", keycode);
	if (keycode == 15)
		frac_init(data);
	if (keycode == 53)
		out_prog(data);
	if (keycode == 123 || keycode == 0)
		data->frac.limit_x -= (0.5 * data->frac.zoom);
	if (keycode == 124 || keycode == 2)
		data->frac.limit_x += (0.5 * data->frac.zoom);
	if (keycode == 125 || keycode == 1)
		data->frac.limit_y -= (0.5 * data->frac.zoom);
	if (keycode == 126 || keycode == 13)
		data->frac.limit_y += (0.5 * data->frac.zoom);
	if (keycode == 69)
		data->frac.ite_def += 10;
	if (keycode == 78)
		if (data->frac.ite_def > 10)
			data->frac.ite_def -= 10;
	if (keycode == 8 || keycode == 9 || keycode == 11)
		key_color(keycode, data);
	render(data);
	return (0);
}

static int	mouse_event(int button, int x, int y, t_mlx *data)
{
	ft_printf("%d %d\n", x, y);
	if (button == 4)
		zoom_in(data, 1.3, x, y);
	if (button == 5)
	{
		data->frac.zoom *= 1.3;
		render(data);
	}
	return (0);
}

void	events_init(t_mlx *data)
{
	mlx_hook(data->win, 2, 0, &key_event, data);
	mlx_hook(data->win, 17, 0, &out_prog, data);
	mlx_hook(data->win, 4, 0, &mouse_event, data);
}
