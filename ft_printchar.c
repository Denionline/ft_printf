/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printchar.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dximenes <dximenes@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/26 17:31:21 by dximenes          #+#    #+#             */
/*   Updated: 2025/05/04 20:49:01 by dximenes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/ft_printf.h"

int	ft_printchar(int c, t_flag *flags)
{
	size_t	bytes;

	bytes = 0;
	if (flags->digit && !ft_strchr("cspdiuxX%", *flags->format) && c)
		bytes += ft_printflags(flags, (const char *)&c);
	else
		bytes = write(1, &c, 1);
	return (bytes);
}
