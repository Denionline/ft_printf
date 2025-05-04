/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printnbr.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dximenes <dximenes@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/26 17:34:45 by dximenes          #+#    #+#             */
/*   Updated: 2025/05/04 21:37:10 by dximenes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/ft_printf.h"

int	ft_printnbr(int nbr, t_flag *flags)
{
	const char	*string = ft_itoa(nbr);
	size_t		bytes;

	bytes = 0;
	if (!string)
		return (bytes);
	if (flags->digit && !ft_strchr("cspdiuxX%", *flags->format))
		bytes = ft_printflags(flags, string);
	else
		while (string[bytes])
			bytes += ft_printchar(string[bytes], flags);
	free((void *)string);
	return (bytes);
}
