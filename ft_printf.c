/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dximenes <dximenes@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/23 10:33:48 by dximenes          #+#    #+#             */
/*   Updated: 2025/04/24 17:03:39 by dximenes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_printf(const char *format, ...)
{
	va_list args;

	va_start(args, format);
	while (*format)
	{
		if (*format == '%' && *(format + 1))
		{
			format++;
			if (*format == 's')
				ft_putstr_fd(va_arg(args, char*), 1);
			if (*format == 'c')
				ft_putchar_fd((char)va_arg(args, int), 1);
			if (*format == 'd' || *format == 'i')
				ft_putnbr_fd(va_arg(args, int), 1);
			if (*format == 'u')
				ft_putnbr_fd(va_arg(args, int), 1);
			if (*format == 'x' || *format == 'X')
				ft_puthexa_fd(va_arg(args, int), *format, 1);
			if (*format == '%')
				ft_putchar_fd(*format, 1);
			if (*format == 'p')
			{
				ft_putstr_fd("0x", 1);
				ft_puthexa_fd(va_arg(args, unsigned long long), *format, 1);
			}
		}
		else
			ft_putchar_fd(*format, 1);
		format++;
	}
	va_end(args);
	return (1);
}
