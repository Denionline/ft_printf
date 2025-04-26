/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dximenes <dximenes@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/23 10:33:48 by dximenes          #+#    #+#             */
/*   Updated: 2025/04/26 17:49:33 by dximenes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/ft_printf.h"

int	ft_printf(const char *format, ...)
{
	size_t	bytes;
	va_list	args;

	bytes = 0;
	va_start(args, format);
	while (*format)
	{
		if (*format == '%' && *(format + 1))
		{
			format++;
			if (*format == 's')
				bytes += ft_printstr(va_arg(args, char*));
			if (*format == 'c' || *format == '%')
				bytes += ft_printchar((char)va_arg(args, int));
			if (*format == 'd' || *format == 'i')
				bytes += ft_printnbr(va_arg(args, int));
			if (*format == 'u')
				bytes += ft_printnbr(va_arg(args, int));
			if (*format == 'x' || *format == 'X')
				bytes += ft_printhexa(va_arg(args, int), *format);
			if (*format == 'p')
				bytes += ft_printptr(va_arg(args, unsigned long long));
		}
		else
			bytes += ft_printchar(*format);
		format++;
	}
	va_end(args);
	return (bytes);
}
