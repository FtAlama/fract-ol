/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calculs.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alama <alama@student.s19.be>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/24 17:27:10 by alama             #+#    #+#             */
/*   Updated: 2024/06/24 17:48:42 by alama            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tools.h"

double	map(double unsc_num, double new_min, double new_max, double old_max)
{
	return ((new_max - new_min) * (unsc_num - 0) / (old_max - 0) + new_min);
}
