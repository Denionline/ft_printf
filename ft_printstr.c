/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printstr.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dximenes <dximenes@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/26 17:32:30 by dximenes          #+#    #+#             */
/*   Updated: 2025/05/02 11:35:30 by dximenes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/ft_printf.h"

int	ft_printstr(const char *str)
{
	size_t	bytes;

	bytes = 0;
	if (!str)
		bytes = ft_printstr("(null)");
	else if (*str)
		while (str[bytes])
			bytes += ft_printchar(str[bytes]);
	return (bytes);
}
