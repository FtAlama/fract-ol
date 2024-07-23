/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calculs.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alama <alama@student.s19.be>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/24 17:27:10 by alama             #+#    #+#             */
/*   Updated: 2024/07/23 17:19:46 by alama            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tools.h"

double	map(double unsc_num, double new_min, double new_max, double old_max)
{
	return ((new_max - new_min) * (unsc_num - 0) / (old_max - 0) + new_min);
}

void	rotate_point(t_complex *point, double angle_x, double angle_y)
{
	double	tmp_x;
	double	tmp_y;
	double	tmp_z;

	tmp_y = point->y * cos(angle_x) - point->z * sin(angle_x);
	tmp_z = point->y * sin(angle_x) + point->z * cos(angle_x);
	point->y = tmp_y;
	point->z = tmp_z;
	tmp_x = point->x * cos(angle_y) + point->z * sin(angle_y);
	tmp_z = -point->x * sin(angle_y) + point->z * cos(angle_y);
	point->x = tmp_x;
	point->z = tmp_z;
}

void	translate_point(t_complex *point, double tx, double ty, double tz)
{
	point->x += tx;
	point->y += ty;
	point->z += tz;
}
