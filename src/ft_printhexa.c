/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printhexa.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dximenes <dximenes@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/23 16:28:10 by dximenes          #+#    #+#             */
/*   Updated: 2025/04/26 17:49:09 by dximenes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/ft_printf.h"

int	ft_printhexa(unsigned long long n, int c)
{
	const char	*hexa = "0123456789abcdef";
	size_t		bytes;

	bytes = 0;
	if (n >= 16)
		bytes += ft_printhexa((n / 16), c);
	if (c == 'X')
		bytes += ft_printchar((char)ft_toupper(hexa[n % 16]));
	else
		bytes += ft_printchar(hexa[n % 16]);
	return (bytes);
}