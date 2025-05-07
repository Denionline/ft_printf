/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printflags.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dximenes <dximenes@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/04 16:58:54 by dximenes          #+#    #+#             */
/*   Updated: 2025/05/07 17:01:18 by dximenes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/ft_printf.h"

static void	fh_setwp(t_flag *flags)
{
	while (!ft_isdigit(*flags->format) && *flags->format 	)
		if (*flags->format++ != '.')
			break;
	if (ft_isdigit(*flags->format))
	{
		flags->width = ft_atoi(flags->format);
		while (ft_isdigit(*flags->format))
			flags->format++;
	}
	if (*flags->format++ == '.')
	{
		flags->precision = ft_atoi(flags->format);
		while (ft_isdigit(*flags->format))
			flags->format++;
	}
}

static size_t	fh_printpad(t_flag *flags, int size)
{
	size_t	bytes;

	bytes = 0;
	if (flags->negative)
		bytes += ft_printchar('-', flags, FALSE);
	while (((size--) - flags->hash) > flags->plus)
		bytes += ft_printchar(flags->pad, flags, FALSE);
	if (flags->plus)
		bytes += ft_printchar('+', flags, FALSE);
	return (bytes);
}

static	size_t	fh_newstrlen(const char *string, t_flag *flags)
{
	int	lstring;

	lstring = ft_strlen(string);
	if (flags->symbol == 's')
	{
		if (flags->precision < lstring && flags->point)
			lstring = flags->precision;
		flags->precision = 0;
	}
	if (flags->symbol != 's')
	{
		if (flags->precision >= lstring)
			flags->precision -= lstring;
		if (flags->precision < lstring)
			flags->precision = 0;
		lstring += flags->precision;
	}
	return (lstring);
}

static char	*fh_getstring(const char *string, t_flag *flags)
{
	int		i;
	int		lstring;
	char	*temp;
	char	*newstring;

	lstring = fh_newstrlen(string, flags);
	temp = (char *)malloc(lstring + 1);
	if (!temp)
		return (0);
	ft_memset(temp, '0', lstring);
	temp[lstring] = '\0';
	if (flags->hash && flags->symbol != 's')
		newstring = ft_strjoin("0x", temp);
	else
		newstring = ft_strdup(temp);
	free(temp);
	i = -1;
	while (++i < (lstring - flags->precision))
		newstring[i + flags->precision + flags->hash] = string[i];
	return (newstring);
}

size_t	ft_printflags(t_flag *flags, const char *string)
{
	char	*newstring;
	size_t	bytes;
	size_t	lnewstring;

	if (!flags->digit && flags->point)
		return (ft_printstr(string, flags, FALSE));
	fh_setwp(flags);
	newstring = fh_getstring(string, flags);
	if (*flags->format == '0')
		flags->pad = '0';
	else
		flags->pad = ' ';
	lnewstring = ft_strlen(newstring) + (*newstring == '\0');
	bytes = 0;
	if (!flags->minus)
		bytes += fh_printpad(flags, flags->width - lnewstring);
	bytes += ft_printstr(newstring, flags, FALSE);
	if (flags->minus)
		bytes += fh_printpad(flags, flags->width - lnewstring);
	free(newstring);
	return (bytes);
}
