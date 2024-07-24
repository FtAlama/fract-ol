/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alama <alama@student.s19.be>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/02 14:37:27 by alama             #+#    #+#             */
/*   Updated: 2024/05/02 16:11:10 by alama            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_putnbr(long nbr, int *count)
{
	char	c;

	if (nbr >= 0 && nbr <= 9)
	{
		c = nbr + '0';
		ft_write(c, count);
	}
	else if (nbr < 0)
	{
		ft_write('-', count);
		nbr *= -1;
		ft_putnbr(nbr, count);
	}
	else
	{
		ft_putnbr(nbr / 10, count);
		ft_putnbr(nbr % 10, count);
	}
}
