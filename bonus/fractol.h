/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alama <alama@student.s19.be>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/20 19:16:01 by alama             #+#    #+#             */
/*   Updated: 2024/06/24 17:59:59 by alama            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# include "minilibx/mlx.h"
# include "printf/ft_printf.h"
# include "tools_lib/tools.h"
# include <stdio.h>

# define ERROR_MESSAGE "type :\t\"mandelbrot\" or\n      \t\"julia int int\n\""
# define WIDTH	1280
# define HEIGHT	720

typedef struct s_frac
{
	int		escape_value;
	int		ite_def;
	double	limit_x;
	double	limit_y;
	double	zoom;
	double	julia_x;
	double	julia_y;
}	t_frac;

typedef struct s_complex
{
	double	x;
	double	y;
}	t_complex;

typedef struct s_img
{
	void	*ptr_img;
	char	*pixels_ptr;
	int		bpp;
	int		endian;
	int		line_len;
}	t_img;

typedef struct s_mlx
{
	void	*mlx;
	void	*win;
	char	*name;
	int		err_out;
	t_img	img;
	t_frac	frac;
}	t_mlx;

int		out_prog(t_mlx *data);
void	events_init(t_mlx *data);
void	frac_init(t_mlx *data);
void	render(t_mlx *data);

#endif
