/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alama <alama@student.s19.be>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/23 19:03:06 by alama             #+#    #+#             */
/*   Updated: 2024/07/23 22:20:01 by alama            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TOOLS_H
# define TOOLS_H

# include <math.h>
# include "../printf/ft_printf.h"

typedef struct s_complex
{
	double	x;
	double	y;
	double	z;
	double	rx;
	double	ry;
	double	tx;
	double	ty;
	double	tz;
}	t_complex;

int		ft_strncmp(char *s1, char *s2, int size);
double	atodbl(char *s);
double	map(double unsc_num, double new_min, double new_max, double old_max);
void	rotate_point(t_complex *point, double angle_x, double angle_y);
void	translate_point(t_complex *point, double tx, double ty, double tz);

#endif
