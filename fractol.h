/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alama <alama@student.s19.be>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/03 14:38:47 by alama             #+#    #+#             */
/*   Updated: 2024/06/03 20:11:28 by alama            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# include "minilibx/mlx.h"
# include <stdlib.h>
# include <stdio.h>

typedef struct s_data
{
	void	*mlx;
	void	*win;
	void	*img;
	char	*buff_img;
	int		color;
	int		err_output;
	int		w;
	int		h;
}	t_data;

int	out_prog(t_data *data);
int	key_event(int keycode, t_data *data);
int	mouse_event(int button, int x, int y, t_data *data);

#endif
