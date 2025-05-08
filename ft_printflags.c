/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printflags.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dximenes <dximenes@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/04 16:58:54 by dximenes          #+#    #+#             */
/*   Updated: 2025/05/08 18:22:59 by dximenes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/ft_printf.h"

static void	fh_setwp(t_flag *flags)
{
	if (*flags->format == '0')
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
	while (((size--) - flags->hash) > flags->plus)
		bytes += ft_printchar(flags->pad, flags, FALSE);
	return (bytes);
}

static	size_t	fh_newstrlen(const char *string, t_flag *flags)
{
	int	lstring;

	lstring = ft_strlen(string);
	if (!ft_strncmp(string, "(null)", lstring) && flags->prec < lstring)
		return (0);
	if (flags->symbol == 's' && flags->point)
	{
		if (flags->prec < lstring && flags->point)
			lstring = flags->prec;
		if (flags->prec < 0)
			lstring = 0;
		else
			flags->prec = 0;
	}
	else if (flags->point && flags->digit)
	{
		if (flags->prec >= lstring)
			flags->prec -= lstring;
		if (flags->prec < lstring)
			flags->prec = 0;
		lstring += flags->prec;
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

	lstring = fh_newstrlen(string, flags) + flags->negative;
	temp = (char *)malloc(lstring + 1);
	if (!temp)
		return (0);
	ft_memset(temp, '-', lstring);
	temp[lstring] = '\0';
	if (flags->hash && flags->symbol != 's')
		newstring = ft_strjoin("0x", temp);
	else
		newstring = ft_strdup(temp);
	free(temp);
	diff = flags->hash;
	if (flags->prec > 0)
		diff += flags->prec;
	i = -1;
	while (++i < lstring)
		newstring[i + diff + flags->negative] = string[i];
	return (newstring);
}

size_t	ft_printflags(t_flag *flags, const char *string)
{
	char	*newstr;
	size_t	bytes;
	size_t	lnewstr;

	if (!flags->digit && flags->point && flags->symbol == 's')
		return (0);
	if (flags->exist)
		fh_setwp(flags);
	newstr = fh_getstring(string, flags);
	lnewstr = ft_strlen(newstr) + (*newstr == '\0');
	if (flags->point && flags->prec == -1)
		lnewstr--;
	bytes = 0;
	if (flags->exist && !flags->minus)
		bytes += fh_printpad(flags, flags->width - lnewstr);
	if (ft_strncmp(string, "(null)", 7))
		bytes += ft_printstr(newstr, flags, FALSE);
	if (flags->exist && flags->minus)
		bytes += fh_printpad(flags, flags->width - lnewstr);
	free(newstr);
	return (bytes);
}
