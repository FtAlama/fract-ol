/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   strings_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alama <alama@student.s19.be>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/23 19:24:52 by alama             #+#    #+#             */
/*   Updated: 2024/07/23 22:19:27 by alama            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tools.h"

int	ft_strncmp(char *s1, char *s2, int size)
{
	int	i;

	i = 0;
	while (i < size && s1[i] && s2[i] && s1[i] == s2[i])
		i++;
	return (s1[i] - s2[i]);
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
	while ((*s >= 9 && *s <= 13) || (*s == 32))
		s++;
	while (*s == '+' || *s == '-')
		if (*s++ == '-')
			sign = -sign;
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
	return ((i_part + frac_part) * sign);
}
