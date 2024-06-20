/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools.utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alama <alama@student.s19.be>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/05 16:13:29 by alama             #+#    #+#             */
/*   Updated: 2024/06/20 18:17:00 by alama            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

double	scale(double unscaled_num, double new_min, double new_max, double old_max)
{
	return ((new_max - new_min) * (unscaled_num - 0) / (old_max - 0) + new_min);
}

t_complex	sum_complex(t_complex z1, t_complex z2)
{
	t_complex result;

	result.real = z1.real + z2.real;
	result.ima = z1.ima + z2.ima;
	return (result);
}

t_complex	square_complex(t_complex z)
{
	t_complex	result;

	result.real = (z.real * z.real) - (z.ima * z.ima);
	result.ima = 2 * z.real * z.ima;
	return result;
}

int	ft_strncmp(char *s1, char *s2, int size)
{
	int	i;

	i = 0;
	while (i < size && s1[i] && s2[i] && s1[i] == s2[i])
		i++;
	return (s1[i] - s2[i]);
}

void	ft_putstr(char *str)
{
	while (*str != '\0')
	{
		write(1, str, 1);
		str++;
	}
}

double	atodbl(char *s)
{
	long	i_part;
	double	frac_part;
	double	pow;
	int		sign;

	i_part = 0;
	frac_part = 0;
	sign = 1;
	pow = 1;
	while ((*s >= 9 && *s <= 13) || 32 == *s)
		s++;
	while (*s == '+' || *s == '-')
	{
		if (*s++ == '-')
			sign = -sign;
	}
	while (*s != '.' && *s)
		i_part = (i_part * 10) + (*s++ - '0');
	if (*s == '.')
		s++;
	while (*s)
	{
		pow /= 10;
		frac_part = frac_part + (*s - '0') * pow;
		s++;
	}
	long l = (i_part + frac_part) * sign;
	printf("%ld\n", l);
	return (l);
}
