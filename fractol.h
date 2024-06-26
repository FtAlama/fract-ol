/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alama <alama@student.s19.be>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/03 14:38:47 by alama             #+#    #+#             */
/*   Updated: 2024/06/28 17:44:53 by alama            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# include "minilibx/mlx.h"
# include <stdlib.h>
# include <stdio.h>
# include <unistd.h>

# define ERROR_MESSAGE "type :\t\"mandelbrot\" or\n      \t\"julia int int\" "

//# define WIDTH		960
# define WIDTH		1280
//# define HEIGHT		800
# define HEIGHT		720
# define BLACK		0x000000
# define WHITE		0xFFFFFF
# define RED		0xFF0000
# define GREEN		0x00FF00
# define BLUE		0x0000FF
# define HOT_PINK	0xFF66B2
# define SUN		0x330000
# define BLUE_SKY	0xC1E7F7
# define ZOOM_FACTOR_IN	1.2
# define ZOOM_FACTOR_OUT	0.8

typedef	struct	s_limit
{
	double x;
	double y;
}	t_limit;

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
	double	escape_value;
	int		iterations_definition;
	t_limit	limit;
	double	zoom;
	double	julia_x;
	double	julia_y;
}	t_fract;

typedef struct s_complex
{
	double	real;
	double	ima;
}	t_complex;

int			out_prog(t_fract *data);
int			key_event(int keycode, t_fract *data);
int			mouse_event(int button, int x, int y, t_fract *data);
int			ft_strncmp(char *s1, char *s2, int size);
void		ft_putstr(char *str);
void		events_init(t_fract *frac);
void		data_init(t_fract *frac);
void		render(t_fract *frac);
double		scale(double unscaled_num, double new_min, double new_max, double old_max);
t_complex	square_complex(t_complex z);
t_complex	sum_complex(t_complex z1, t_complex z2);
double		atodbl(char *s);
void		zoom_and_render(t_fract *frac, double zoom_factor, int x, int y);
void		zoom_in(t_fract *frac, double zoom_factor, int x, int y);
void		render_region(t_fract *frac, int start_x, int start_y, int end_x, int end_y);

#endif
