/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alama <alama@student.s19.be>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/23 19:03:06 by alama             #+#    #+#             */
/*   Updated: 2024/06/24 17:48:15 by alama            ###   ########.fr       */
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

int		ft_strncmp(char *s1, char *s2, int size);
double	atodbl(char *s);
double	map(double unsc_num, double new_min, double new_max, double old_max);

#endif
