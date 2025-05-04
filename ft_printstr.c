/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printstr.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dximenes <dximenes@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/26 17:32:30 by dximenes          #+#    #+#             */
/*   Updated: 2025/05/04 18:13:26 by dximenes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/ft_printf.h"

int	ft_printstr(const char *str, t_flag *flags)
{
	size_t	bytes;

	bytes = 0;
	if (!str)
		bytes = ft_printstr("(null)", flags);
	else if (flags->digit && !ft_strchr("cspdiuxX%", *flags->format))
		bytes += ft_printflags(flags, str);
	else
		while (*str)
			bytes += ft_printchar(*str++, flags);
	return (bytes);
}
