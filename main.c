/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alama <alama@student.s19.be>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/03 14:17:57 by alama             #+#    #+#             */
/*   Updated: 2024/06/18 15:29:24 by alama            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	data_init(t_fract *frac)
{
	frac->escape_value = 4;
	frac->iterations_definition = 300;
	frac->limit.x = 0.0;
	frac->limit.y = 0.0;
	frac->zoom = 1.0;
}

void	fract_init(t_fract *frac)
{
	frac->mlx = mlx_init();
	frac->err_out = 0;
	if (!frac->mlx)
	{
		frac->err_out = 1;
		out_prog(frac);
	}
	frac->win = mlx_new_window(frac->mlx, WIDTH, HEIGHT, frac->name);
	if (!frac->win)
	{
		frac->err_out = 1;
		out_prog(frac);
	}
	frac->img.ptr_img = mlx_new_image(frac->mlx, WIDTH, HEIGHT);
	if (!frac->img.ptr_img)
	{
		frac->err_out = 1;
		out_prog(frac);
	}
	frac->img.pixels_ptr = mlx_get_data_addr(frac->img.ptr_img,
			&frac->img.bits_pp,
			&frac->img.line_len,
			&frac->img.endian);
	events_init(frac);
	data_init(frac);
}

int	main(int argc, char *argv[])
{
	t_fract	data;

	if ((argc == 2 && !ft_strncmp(argv[1], "mandelbrot", 10))
		|| (argc == 4 && !ft_strncmp(argv[1], "julia", 5)))
	{
		data.name = argv[1];
		fract_init(&data);
		render(&data);
		mlx_loop(data.mlx);
	}
	else
	{
		ft_putstr(ERROR_MESSAGE);
		exit(EXIT_FAILURE);
	}
	return (0);
}
