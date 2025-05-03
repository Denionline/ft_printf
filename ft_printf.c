/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dximenes <dximenes@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/23 10:33:48 by dximenes          #+#    #+#             */
/*   Updated: 2025/05/03 09:40:17 by dximenes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/ft_printf.h"

static size_t	fh_printflag(const char *format)
{
	
}

static size_t	fh_printsy(int sy, va_list args)
{
	if (sy == 's')
		return (ft_printstr(va_arg(args, char *)));
	if (sy == 'c')
		return (ft_printchar((char)va_arg(args, int)));
	if (sy == '%')
		return (ft_printchar(sy));
	if (sy == 'd' || sy == 'i')
		return (ft_printnbr(va_arg(args, int)));
	if (sy == 'u')
		return (ft_printuint(va_arg(args, unsigned int)));
	if (sy == 'x' || sy == 'X')
		return (ft_printhexa(va_arg(args, int), sy));
	if (sy == 'p')
		return (ft_printptr(va_arg(args, void *)));
	return (0);
}

int	ft_printf(const char *format, ...)
{
	va_list	args;
	size_t	bytes;

	if (!format || !(*format))
		return (0);
	va_start(args, format);
	bytes = 0;
	while (*format)
	{
		if (*format == '%' && ft_strchr("cspdiuxX%", *(format + 1)))
		{
			if (ft_strchr(" 0123456789", *(format + 1)))
				bytes += fh_printflag(format + 1);
			bytes += fh_printsy(*(++format), args);
		}
		else
			bytes += ft_printchar(*format);
		format++;
	}
	va_end(args);
	return (bytes);
}
