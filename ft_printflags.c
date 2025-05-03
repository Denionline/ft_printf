/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printflags.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dximenes <dximenes@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/03 14:58:48 by dximenes          #+#    #+#             */
/*   Updated: 2025/05/03 18:03:23 by dximenes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// #include "include/ft_printf.h"

// int	ft_printflags(const char *format, va_list args, t_flag	*flags)
// {
// 	size_t	bytes;
// 	size_t	size;

// 	if (flags->zero)
// 		format++;
// 	bytes = 0;
// 	while (!ft_strchr("cspdiuxX%", format[bytes]))
// 		bytes++;
// 	if (ft_isdigit(*format))
// 		size = ft_atoi(ft_substr(format, 0, bytes));
// 	return (bytes);
// }