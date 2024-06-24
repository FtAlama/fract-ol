/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_base_unsigned.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alama <alama@student.s19.be>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/28 16:54:11 by alama             #+#    #+#             */
/*   Updated: 2024/05/02 14:44:15 by alama            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static unsigned int	ft_strlen(char *base)
{
	unsigned int	i;

	i = 0;
	while (base[i])
		i++;
	return (i);
}

static int	ft_verif_base(char *base)
{
	int	i;
	int	j;
	int	len;

	i = 0;
	len = ft_strlen(base);
	if (len == 1)
		return (0);
	while (base[i] != '\0')
	{
		if (base[i] == '-' || base[i] == '+')
			return (0);
		j = i + 1;
		while (j < len)
		{
			if (base[i] == base[j])
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}

void	ft_putnbr_base_unsigned(unsigned int nbr, char *base, int *count)
{
	unsigned int	len;

	len = ft_strlen(base);
	if (ft_verif_base(base) == 1)
	{
		if (nbr < len)
			ft_write(base[nbr], count);
		if (nbr >= len)
		{
			ft_putnbr_base_unsigned(nbr / len, base, count);
			ft_putnbr_base_unsigned(nbr % len, base, count);
		}
	}
}
