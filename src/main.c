/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alama <alama@student.s19.be>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/20 19:15:05 by alama             #+#    #+#             */
/*   Updated: 2024/07/24 21:51:23 by alama            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static void	window_set(t_mlx *data)
{
	int	width;
	int	height;

	if (data->nb_name == 2)
	{
		width = WIDTH_L;
		height = HEIGHT_L;
	}
	else
	{
		width = WIDTH;
		height = HEIGHT;
	}
	data->win = mlx_new_window(data->mlx, width, height, data->name);
	if (!data->win)
	{
		data->err_out = 1;
		out_prog(data);
	}
	data->img.ptr_img = mlx_new_image(data->mlx, width, height);
	if (!data->img.ptr_img)
	{
		data->err_out = 1;
		out_prog(data);
	}
}

static void	data_init(t_mlx *data)
{
	data->err_out = 0;
	data->mlx = mlx_init();
	if (!data->mlx)
	{
		data->err_out = 1;
		out_prog(data);
	}
	window_set(data);
	data->img.pixels_ptr = mlx_get_data_addr(data->img.ptr_img,
			&data->img.bpp, &data->img.line_len, &data->img.endian);
	events_init(data);
}

static void	if_is_julia(t_mlx *data, char *x, char *y, int argc)
{
	if (argc == 2)
	{
		data->frac.julia_x = -0.8;
		data->frac.julia_y = 0.156;
		data->frac.is_set = 0;
	}
	else if (argc == 4)
	{
		data->frac.julia_x = atodbl(x);
		data->frac.julia_y = atodbl(y);
		data->frac.is_set = 1;
	}
	data->nb_name = 1;
}

int	main(int argc, char *argv[])
{
	t_mlx	data;

	if ((argc == 2 && !ft_strncmp(argv[1], "mandelbrot", 10))
		|| ((argc == 4 || argc == 2) && !ft_strncmp(argv[1], "julia", 5))
		|| (argc == 2 && !ft_strncmp(argv[1], "lorenz", 6)))
	{
		if (!ft_strncmp(argv[1], "julia", 5))
			if_is_julia(&data, argv[2], argv[3], argc);
		else if (!ft_strncmp(argv[1], "lorenz", 6))
			data.nb_name = 2;
		else
			data.nb_name = 0;
		data.name = argv[1];
		data_init(&data);
		frac_init(&data);
		mlx_loop(data.mlx);
	}
	else
	{
		ft_printf(ERROR_MESSAGE);
		ft_printf(" or\n\t\"lorenz\"\n");
		exit(EXIT_FAILURE);
	}
	return (0);
}
