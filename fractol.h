/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alama <alama@student.s19.be>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/03 14:38:47 by alama             #+#    #+#             */
/*   Updated: 2024/06/13 20:17:10 by alama            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# include "minilibx/mlx.h"
# include <stdlib.h>
# include <stdio.h>
# include <stdio.h>
# include <unistd.h>

# define ERROR_MESSAGE "type :\t\"mandelbrot\" or\n      \t\"julia int int\" ";

# define WIDTH	960
# define HEIGHT	800

typedef struct s_img
{
	void	*ptr_img;
	char	*pixels_ptr;
	int		bits_pp;
	int		endian;
	int		line_len;
}	t_img;

typedef struct s_fract 
{
	void	*mlx;
	void	*win;
	t_img	img;
	char	*name;
	int		err_out;
}	t_fract;

int		out_prog(t_fract *data);
int		key_event(int keycode, t_fract *data);
int		mouse_event(int button, int x, int y, t_fract *data);
int		ft_strncmp(char *s1, char *s2, int size);
void	ft_putstr(char *str);
void	events_init(t_fract *frac);
void	data_init(t_fract *frac);
void	render(t_fract *frac);

#endif
