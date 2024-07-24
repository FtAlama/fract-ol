/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alama <alama@student.s19.be>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/20 19:16:01 by alama             #+#    #+#             */
/*   Updated: 2024/07/24 23:50:54 by alama            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# include "mlx.h"
# include "ft_printf.h"
# include "tools.h"
# include <stdio.h>
# include "color.h"

# define ERROR_MESSAGE "type :\t\"mandelbrot\" or\n      \t\"julia int int\""
# define WIDTH_L	1280
# define HEIGHT_L	720
# define WIDTH	580
# define HEIGHT	430
# define A		10
# define B		28
# define C		2.66666

typedef struct s_frac
{
	int		escape_value;
	int		ite_def;
	double	limit_x;
	double	limit_y;
	double	zoom;
	double	julia_x;
	double	julia_y;
	int		is_set;
}	t_frac;

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
	void		*mlx;
	void		*win;
	char		*name;
	int			err_out;
	t_img		img;
	t_frac		frac;
	int			nb_name;
	int			p[15];
	int			p1;
	int			p2;
	int			p3;
	t_complex	d;
}	t_mlx;

int		out_prog(t_mlx *data);
void	events_init(t_mlx *data);
void	frac_init(t_mlx *data);
void	render(t_mlx *data);
void	what_frac(t_complex *z, t_complex *c, t_mlx *data);
void	zoom_and_render(t_mlx *data, double zoom_factor, int x, int y);
int		mouse_press(int button, int x, int y, t_mlx *data);
void	zoom_in(t_mlx *data, double zoom_factor, int x, int y);

#endif
