/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printnbr.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dximenes <dximenes@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/26 17:34:45 by dximenes          #+#    #+#             */
/*   Updated: 2025/04/26 19:00:11 by dximenes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/ft_printf.h"

int ft_printnbr(int  nbr)
{
	const char	*str = ft_itoa(nbr);
	size_t		bytes;

	bytes = 0;
	while (str[bytes])
		bytes += ft_printchar(str[bytes]);
	return (bytes);
}