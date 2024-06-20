/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_event.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alama <alama@student.s19.be>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/03 15:26:41 by alama             #+#    #+#             */
/*   Updated: 2024/06/20 21:31:25 by alama            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	out_prog(t_fract *data)
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
		printf("sucess close\n");
		exit(EXIT_SUCCESS);
	}
	else if (data->err_out == 1)
		perror("...Malloc allocation failed...\n");
	exit(EXIT_FAILURE);
	return (0);
}

int	mouse_event(int button, int x, int y, t_fract *frac)
{
	double	dx;
	double	dy;
	
	dx = x;
	dy = y;
	dx = (scale(dx, -2, 2, WIDTH) * frac->zoom) + frac->limit.x;
	dy = (scale(dy, 2, -2, HEIGHT) * frac->zoom) + frac->limit.y;
	printf("%f, %f \n", dx, dy);
	if (button == 4)
	{
		frac->zoom *= 0.45;
	}
	if (button == 5)
	{
		frac->zoom *= 1.45;
		//frac->iterations_definition += 10;
		frac->limit.x = dx;
		frac->limit.y = dy;
	}
	render(frac);
	return (0);
}

int	key_event(int keycode, t_fract *data)
{
	if (keycode == 53)
		out_prog(data);
	if (keycode == 123)
		data->limit.x -= (0.5 * data->zoom);
	if (keycode == 124)
		data->limit.x += (0.5 * data->zoom);
	if (keycode == 125)
		data->limit.y -= (0.5 * data->zoom);
	if (keycode == 126)
		data->limit.y += (0.5 * data->zoom);
	if (keycode == 69)
		data->iterations_definition += 10;
	if (keycode == 78)
		data->iterations_definition -= 10;
	render(data);
	return (0);
}

void	events_init(t_fract *frac)
{
	mlx_hook(frac->win, 2, 0, &key_event, frac);
	mlx_hook(frac->win, 4, 0, &mouse_event, frac);
	mlx_hook(frac->win, 17, 0, &out_prog, frac);
}
