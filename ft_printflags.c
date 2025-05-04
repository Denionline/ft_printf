/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printflags.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dximenes <dximenes@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/04 16:58:54 by dximenes          #+#    #+#             */
/*   Updated: 2025/05/04 19:37:31 by dximenes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/ft_printf.h"

static size_t	fh_printpad(t_flag *flags, int size)
{
	size_t	bytes;

	bytes = 0;
	if (flags->hash)
		bytes += ft_printchar('0', flags) + ft_printchar(*flags->format, flags);
	while ((size--) > flags->plus)
		bytes += ft_printchar(flags->pad, flags);
	if (flags->plus)
		bytes += ft_printchar('+', flags);
	return (bytes);
}

size_t	ft_printflags(t_flag *flags, const char *string)
{
	size_t	bytes;
	size_t	size;
	int		width;

	if (*flags->format == '0')
		flags->pad = '0';
	else
		flags->pad = ' ';
	while (!ft_isdigit(*flags->format))
		flags->format++;
	width = 0;
	while (flags->digit && ft_isdigit(*flags->format))
		width = width * 10 + (*(flags->format++) - '0');
	size = ft_strlen(string);
	bytes = 0;
	if (!flags->minus)
		bytes += fh_printpad(flags, (width - flags->hexa) - size);
	if (flags->hexa)
		bytes += ft_printstr("0x", flags);
	while (*string)
		bytes += ft_printchar(*string++, flags);
	if (flags->minus)
		bytes += fh_printpad(flags, (width - flags->hexa) - size);
	return (bytes);
}
