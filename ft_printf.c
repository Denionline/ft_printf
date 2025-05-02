/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dximenes <dximenes@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/23 10:33:48 by dximenes          #+#    #+#             */
/*   Updated: 2025/05/01 09:19:07 by dximenes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/ft_printf.h"

int ft_printf(const char * format, ...)
{
	va_list	args;
	size_t	bytes;
	size_t	i;
	char *	string;

	if (!format || !(*format))
		return (0);
	va_start(args, format);
	string = ft_strdup(format);
	if (!string || !(*string))
		return (0);
	i = 0;
	bytes = 0;
	while (string[i])
	{
		if (string[i] == '%' && string[i + 1])
		{
			i++;
			if (string[i] == 's')
				bytes += ft_printstr(va_arg(args, char *));
			else if (string[i] == 'c')
				bytes += ft_printchar((char)va_arg(args, int));
			else if (string[i] == '%')
				bytes += ft_printchar(string[i]);
			else if (string[i] == 'd' || string[i] == 'i')
				bytes += ft_printnbr(va_arg(args, int));
			else if (string[i] == 'u')
				bytes += ft_printuint(va_arg(args, unsigned int));
			else if (string[i] == 'x' || string[i] == 'X')
				bytes += ft_printhexa(va_arg(args, int), string[i]);
			else if (string[i] == 'p')
				bytes += ft_printptr(va_arg(args, void*));
		}
		else
			bytes += ft_printchar(string[i]);
		i++;
	}
	va_end(args);
	free(string);
	return (bytes);
}
