/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alama <alama@student.s19.be>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/25 14:22:40 by alama             #+#    #+#             */
/*   Updated: 2024/06/23 19:08:01 by alama            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <libc.h>

static void	ft_putstr(va_list args, int *count)
{
	char	*c;

	c = va_arg(args, char *);
	if (c != 0)
	{
		while (*c)
		{
			ft_write(*c, count);
			c++;
		}
	}
	else if (c == 0)
	{
		write(1, "(null)", 6);
		*(count) += 6;
	}
}

static int	ft_va_type(const char *str, va_list args, int *count)
{
	if (*str == 'u')
		ft_putnbr_base_unsigned(va_arg(args, int), "0123456789", count);
	else if (*str == 's')
		ft_putstr(args, count);
	else if (*str == 'c')
		ft_write(va_arg(args, int), count);
	else if (*str == 'x')
		ft_putnbr_base_unsigned(va_arg(args, int), "0123456789abcdef", count);
	else if (*str == 'X')
		ft_putnbr_base_unsigned(va_arg(args, int), "0123456789ABCDEF", count);
	else if (*str == '%')
		ft_write('%', count);
	else if (*str == 'p')
	{
		ft_write('0', count);
		ft_write('x', count);
		ft_putnbr_ptr(va_arg(args, long long), "0123456789abcdef", count);
	}
	else if (*str == 'd' || *str == 'i')
		ft_putnbr(va_arg(args, int), count);
	else
		return (-1);
	return (1);
}

int	ft_printf(const char *str, ...)
{
	va_list	args;
	int		is_false;
	int		count;

	is_false = 1;
	count = 0;
	va_start(args, str);
	while (*str != '\0')
	{
		if (*str == '%')
		{
			str++;
			if (ft_va_type(str, args, &count) == -1)
				is_false = -1;
		}
		else
			ft_write(*str, &count);
		str++;
	}
	va_end(args);
	if (is_false == -1)
		return (-1);
	return (count);
}
/*
int main(void)
{
	int i = 6;
	ft_printf("%%\n");
	printf("%%");

	printf("egvrgrwhbfgerh %d%q%d", );
}
*/
