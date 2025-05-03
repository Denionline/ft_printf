/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printnbr.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dximenes <dximenes@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/26 17:34:45 by dximenes          #+#    #+#             */
/*   Updated: 2025/05/03 18:54:14 by dximenes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/ft_printf.h"

static size_t	fh_printflag(t_flag *flags)
{
	if (flags->zero)
		return (ft_printchar('0'));
	return (0);
}

int	ft_printnbr(int nbr, t_flag *flags)
{
	char	*string;
	int		size;
	int		bytes;

	string = ft_itoa(nbr);
	size = 0;
	bytes = 0;
	while (flags->digit && !ft_strchr("% +-.#", *(flags->format - 1)))
		flags->format -= (++bytes) > 0;
	if (*(flags->format) == '0')
		flags->zero = 1;
	if (flags->digit)
		size = ft_atoi(ft_substr(flags->format, 0, bytes)) - ft_strlen(string);
	bytes = 0;
	while ((size--) > 0)
		bytes += fh_printflag(flags);
	bytes = 0;
	while (string[bytes])
		bytes += ft_printchar(string[bytes]);
	free(string);
	return (bytes);
}
