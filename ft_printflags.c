/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printflags.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dximenes <dximenes@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/09 17:42:34 by dximenes          #+#    #+#             */
/*   Updated: 2025/05/11 14:03:07 by dximenes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/ft_printf.h"

int	ft_printflags(int sy, va_list args, t_flag *flags)
{
	char	prefix[3];
	char	*str;
	int		lprefix;
	int		bytes;
	int		len;
	int		precision;
	int		width;
	int		i;

	precision = 0;
	width = 0;
	lprefix = 0;
	bytes = 0;
	len = 0;

	flags->sy = sy;
	if (sy == 's')
		str = ft_handlestr(va_arg(args, char *), flags);
	if (sy == 'c')
		str = ft_handlechar((char)va_arg(args, int));
	if (sy == '%')
		return (ft_printchar(sy));
	if (sy == 'u')
		str = ft_handleuint(va_arg(args, unsigned int));
	if (sy == 'p')
		str = ft_handleptr(va_arg(args, void *));
	if (sy == 'd' || sy == 'i')
		str = ft_handlenbr(va_arg(args, int), flags);
	if (sy == 'x' || sy == 'X')
		str = ft_handlehexa(va_arg(args, int), sy);
	
	if (!str)
		return (0);
	if ((sy == 'i' || sy == 'd') && !flags->negative)
	{
		if (flags->plus)
			prefix[lprefix++] = '+';
		if (flags->space)
			prefix[lprefix++] = ' ';
	}
	if ((sy == 'x' || sy == 'X') && flags->hash && str[0] != '0')
	{
		prefix[lprefix++] = '0';
		prefix[lprefix++] = flags->sy;
	}
	prefix[lprefix] = 0;

	len = ft_strlen(str);
	len += ft_strlen(prefix);
	if (flags->precision > 0 && flags->sy == 's')
	{
		if (!str && flags->precision < 7)
			str[0] = (flags->precision > 7);
		else if (flags->precision < len)
			str[flags->precision] = '\0';
	}
	else if (flags->precision > 0)
	{
		if (flags->precision > len)
		{
			precision = flags->precision - len;
			len = flags->precision;
		}
	}
	if (flags->width)
	{
		width = flags->width - len - flags->negative;
		len = flags->width;
	}
	
	if (flags->sy == 'c' && str[0] == '\0')
		width--;
	if (flags->zero && !flags->minus && !flags->hash && !flags->dot)
		flags->pad = '0';
	else
		flags->pad = ' ';

	if (flags->negative)
			bytes += ft_printchar('-');

	if (width > 0 && !flags->minus)
		while (width--)
			bytes += ft_printchar(flags->pad);
	i = 0;
	while (prefix[i] != '\0')
		bytes += ft_printchar(prefix[i++]);
	if (precision)
		while (precision--)
			bytes += ft_printchar('0');
	if (flags->sy == 'c' && str[0] == '\0')
		bytes += ft_printchar('\0');
	else
		bytes += ft_printstr(str);
	if (width > 0 && flags->minus)
		while (width--)
			bytes += ft_printchar(flags->pad);
	free(str - flags->negative);
	return (bytes);
}
