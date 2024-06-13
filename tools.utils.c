/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools.utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alama <alama@student.s19.be>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/05 16:13:29 by alama             #+#    #+#             */
/*   Updated: 2024/06/05 17:15:47 by alama            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"



int	ft_strncmp(char *s1, char *s2, int size)
{
	int	i;

	i = 0;
	while (i < size && s1[i] && s2[i] && s[i] == s2[i])
		i++;
	return (s1[i] - s2[i]);
}

void	ft_putst(char *str)
{
	while (*str != '\0')
	{
		write(1, str, 1);
		str++;
	}
}
