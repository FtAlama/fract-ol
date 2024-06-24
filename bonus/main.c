/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alama <alama@student.s19.be>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/20 19:15:05 by alama             #+#    #+#             */
/*   Updated: 2024/06/24 18:01:23 by alama            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static void	data_init(t_mlx *data)
{
	data->err_out = 0;
	data->mlx = mlx_init();
	if (!data->mlx)
	{
		data->err_out = 1;
		out_prog(data);
	}
	data->win = mlx_new_window(data->mlx, WIDTH, HEIGHT, data->name);
	if (!data->win)
	{
		data->err_out = 1;
		out_prog(data);
	}
	data->img.ptr_img = mlx_new_image(data->mlx, WIDTH, HEIGHT);
	if (!data->img.ptr_img)
	{
		data->err_out = 1;
		out_prog(data);
	}
	data->img.pixels_ptr = mlx_get_data_addr(data->img.ptr_img, &data->img.bpp,
			&data->img.line_len, &data->img.endian);
	events_init(data);
}

int	main(int argc, char *argv[])
{
	t_mlx data;

	if ((argc == 2 && !ft_strncmp(argv[1], "mandelbrot", 10))
			|| (argc == 4 && !ft_strncmp(argv[1], "julia", 5)))
	{
		if (!ft_strncmp(argv[1], "julia", 5))
		{
			data.frac.julia_x = atodbl(argv[2]);
			data.frac.julia_y = atodbl(argv[3]);
		}
		data.name = argv[1];
		data_init(&data);
		frac_init(&data);
		mlx_loop(data.mlx);
	}
	else
	{
		ft_printf(ERROR_MESSAGE);
		exit(EXIT_FAILURE);
	}
	return (0);
}
