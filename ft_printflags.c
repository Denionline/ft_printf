/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printflags.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dximenes <dximenes@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/04 16:58:54 by dximenes          #+#    #+#             */
/*   Updated: 2025/05/09 11:55:35 by dximenes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/ft_printf.h"

static void	fh_setwp(t_flag *flags)
{
	if (*flags->format == '0' && !flags->point)
		flags->pad = '0';
	else
		flags->pad = ' ';
	while (ft_strchr("+- ", *flags->format) && *flags->format)
		flags->format++;
	if (ft_isdigit(*flags->format))
	{
		flags->width = ft_atoi(flags->format);
		while (ft_isdigit(*flags->format))
			flags->format++;
	}
	if (*flags->format == '.' && ft_isdigit(*(flags->format + 1)))
	{
		if (*(++flags->format) == '0' && !ft_isdigit(*(flags->format + 1)))
			flags->prec = 0;
		else
			flags->prec = ft_atoi(flags->format);
		while (ft_isdigit(*flags->format))
			flags->format++;
	}
}

static size_t	fh_printpad(t_flag *flags, int size)
{
	size_t	bytes;

	bytes = 0;
	if (flags->negative == 1 && size--)
		bytes += ft_printchar('-', flags, FALSE);
	while ((size--) > flags->plus)
		bytes += ft_printchar(flags->pad, flags, FALSE);
	return (bytes);
}

static	size_t	fh_newstrlen(const char *string, t_flag *flags)
{
	int	lstring;

	lstring = ft_strlen(string);
	if (*string == '0' && flags->prec == 0)
		return (0);
	if (flags->symbol == 's' && flags->point)
	{
		if (*flags->format == '.')
			return (0);
		if (flags->prec < lstring && !flags->null)
			lstring = flags->prec;
		if (flags->null && flags->prec < lstring)
			lstring = 0;
	}
	else if (flags->point && flags->digit)
	{
		if (flags->prec >= lstring)
			flags->diff = flags->prec - lstring;
		if (flags->prec < lstring)
			flags->diff = 0;
		lstring += flags->diff;
	}
	return (lstring);
}

static char	*fh_getstring(const char *string, t_flag *flags)
{
	int		i;
	int		lstring;
	char	*temp;
	char	*newstring;
	int		diff;

	lstring = fh_newstrlen(string, flags) + (flags->negative == 2);
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
	diff = flags->hash;
	if (flags->diff > 0)
		diff += flags->diff;
	i = -1;
	while (++i < lstring)
		newstring[i + diff + (flags->negative == 2)] = string[i];
	return (newstring);
}

size_t	ft_printflags(t_flag *flags, const char *string)
{
	char	*newstr;
	size_t	bytes;
	size_t	lnewstr;
	int		count;

	if (!flags->digit && flags->point && flags->symbol == 's')
		return (0);
	fh_setwp(flags);
	newstr = fh_getstring(string, flags);
	if (flags->negative == 2)
		newstr[0] = '-';
	count = 0;
	if (flags->null && !flags->exist)
		count += 1;
	lnewstr = ft_strlen(newstr) + count;
	bytes = 0;
	if (flags->exist && !flags->minus)
		bytes += fh_printpad(flags, flags->width - lnewstr);
	if ((flags->null && !flags->exist) || !flags->null)
		bytes += ft_printstr(newstr, flags, FALSE);
	if (flags->exist && flags->minus)
		bytes += fh_printpad(flags, flags->width - lnewstr);
	free(newstr);
	return (bytes);
}
