/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dximenes <dximenes@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/23 10:33:48 by dximenes          #+#    #+#             */
/*   Updated: 2025/05/04 21:35:07 by dximenes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/ft_printf.h"

static void	fh_setflag(int c, va_list args, t_flag *flags)
{
	if (c == '+')
		flags->plus = 1;
	if (c == '-')
		flags->minus = 1;
	if (c == '#')
		flags->hash = 1;
	if (c == ' ')
		flags->pad = c;
	if (ft_isdigit(c))
		flags->digit = 1;
	if (c == '.')
	{
		flags->point = 1;
		flags->precision = va_arg(args, int);
	}
}

static size_t	fh_initflag(t_flag *flags)
{
	flags->plus = 0;
	flags->minus = 0;
	flags->digit = 0;
	flags->point = 0;
	flags->hash = 0;
	flags->hexa = 0;
	flags->pad = 0;
	flags->width = 0;
	flags->precision = -1;
	return (0);
}

static size_t	fh_printsy(int sy, va_list args, t_flag *flags)
{
	if (sy == 's')
		return (ft_printstr(va_arg(args, char *), flags));
	if (sy == 'c')
		return (ft_printchar((char)va_arg(args, int), flags));
	if (sy == '%')
		return (ft_printchar(sy, flags));
	if (sy == 'u')
		return (ft_printuint(va_arg(args, unsigned int), flags));
	if (sy == 'p')
		return (ft_printptr(va_arg(args, void *), flags));
	if (sy == 'd' || sy == 'i')
		return (ft_printnbr(va_arg(args, int), flags));
	if (sy == 'x' || sy == 'X')
		return (ft_printhexa(va_arg(args, int), sy, flags));
	return (0);
}

int	ft_printf(const char *format, ...)
{
	va_list	args;
	size_t	bytes;
	t_flag	flags;

	if (!format || !(*format))
		return (0);
	va_start(args, format);
	bytes = fh_initflag(&flags);
	while (*format)
	{
		if (*format == '%' && *(format + 1))
		{
			flags.format = (char *)format + 1;
			while (!ft_strchr("cspdiuxX%", *(++format)))
				fh_setflag(*format, args, &flags);
			bytes += fh_printsy(*format, args, &flags);
		}
		else
			bytes += ft_printchar(*format, &flags);
		format++;
	}
	va_end(args);
	return (bytes);
}
