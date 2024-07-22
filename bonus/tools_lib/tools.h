/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alama <alama@student.s19.be>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/23 19:03:06 by alama             #+#    #+#             */
/*   Updated: 2024/06/26 16:54:17 by alama            ###   ########.fr       */
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
}	t_complex;

int			ft_strncmp(char *s1, char *s2, int size);
double		atodbl(char *s);
double		map(double unsc_num, double new_min, double new_max, double old_max);
t_complex	sum_complex(t_complex z1, t_complex z2);
t_complex	sqr_complex(t_complex z);

#endif
