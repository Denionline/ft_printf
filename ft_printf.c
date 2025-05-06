/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dximenes <dximenes@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/23 10:33:48 by dximenes          #+#    #+#             */
/*   Updated: 2025/05/06 15:22:51 by dximenes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/ft_printf.h"

static void	fh_setflag(int c, t_flag *flags)
{
	int	isthereflag;

	isthereflag = 0;
	if (c == '+')
		flags->plus = (++isthereflag > 0);
	if (c == '-')
		flags->minus = (++isthereflag > 0);
	if (c == '#')
		flags->hash = (++isthereflag > 0);
	if (ft_isdigit(c))
		flags->digit = (++isthereflag > 0);
	if (c == '.')
		flags->point = (++isthereflag > 0);
	flags->exist = (isthereflag > 0);
}

static size_t	fh_printsy(int sy, va_list args, t_flag *flags)
{
	if (sy == 's')
		return (ft_printstr(va_arg(args, char *), flags, flags->exist));
	if (sy == 'c')
		return (ft_printchar((char)va_arg(args, int), flags, flags->exist));
	if (sy == '%')
		return (ft_printchar(sy, flags, flags->exist));
	if (sy == 'u')
		return (ft_printuint(va_arg(args, unsigned int), flags, flags->exist));
	if (sy == 'p')
		return (ft_printptr(va_arg(args, void *), flags, TRUE));
	if (sy == 'd' || sy == 'i')
		return (ft_printnbr(va_arg(args, int), flags, flags->exist));
	if (sy == 'x' || sy == 'X')
		return (ft_printhexa(va_arg(args, int), sy, flags, flags->exist));
	return (0);
}

int	ft_printf(const char *format, ...)
{
	va_list	args;
	size_t	bytes;
	t_flag	flags;

	va_start(args, format);
	ft_memset(&flags, 0, sizeof(flags));
	bytes = 0;
	while (*format)
	{
		if (*format == '%' && *(format + 1))
		{
			flags.format = (char *)format + 1;
			while (!ft_strchr("cspdiuxX%", *(++format)))
				fh_setflag(*format, &flags);
			bytes += fh_printsy(*format, args, &flags);
		}
		else
			bytes += ft_printchar(*format, &flags, FALSE);
		format++;
	}
	va_end(args);
	return (bytes);
}
