/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_ptr.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alama <alama@student.s19.be>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/29 14:43:06 by alama             #+#    #+#             */
/*   Updated: 2024/05/02 14:43:54 by alama            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static unsigned long long	ft_strlen(char *base)
{
	unsigned long long	i;

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

void	ft_putnbr_ptr(unsigned long long nbr, char *base, int *count)
{
	unsigned long long	len;

	len = ft_strlen(base);
	if (ft_verif_base(base) == 1)
	{
		if (nbr < len)
			ft_write(base[nbr], count);
		if (nbr >= len)
		{
			ft_putnbr_ptr(nbr / len, base, count);
			ft_putnbr_ptr(nbr % len, base, count);
		}
	}
}
