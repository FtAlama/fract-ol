/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alama <alama@student.s19.be>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/03 14:17:57 by alama             #+#    #+#             */
/*   Updated: 2024/06/03 22:23:01 by alama            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	set_image(t_data *data)
{
	int	p_bits;
	int	l_bytes;
	int	end;

	data->buff_img = mlx_get_data_addr(data->img, &p_bits, &l_bytes, &end);
}



int	main(void)
{
	t_data *data;

	data = malloc(sizeof(t_data));
	if (!data)
		return (1);
	data->mlx = mlx_init();
	data->w = 1020;
	data->h = 980;
//	mlx_get_screen_size(data->mlx, &data->w, &data->h);
	data->win = mlx_new_window(data->mlx, data->w, data->h, "fract'ol");
	data->img = mlx_new_image(data->mlx, data->w, data->h);
	set_image(data);
	mlx_put_image_to_window(data->mlx, data->win, data->img, 0, 0);
	data->err_output = 0;
	mlx_key_hook(data->win, &key_event, data);
	mlx_hook(data->win, 17, 0, &out_prog, data);
	mlx_loop(data->mlx);
	return (0);
}
