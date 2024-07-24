/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alama <alama@student.s19.be>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/25 14:14:20 by alama             #+#    #+#             */
/*   Updated: 2024/05/02 16:11:24 by alama            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <stdlib.h>
# include <unistd.h>

int		ft_printf(const char *str, ...);
void	ft_write(char c, int *count);
void	ft_putnbr_base_unsigned(unsigned int nbr, char *base, int *count);
void	ft_putnbr_ptr(unsigned long long nbr, char *base, int *count);
void	ft_putnbr(long nbr, int *count);

#endif