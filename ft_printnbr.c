/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printnbr.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dximenes <dximenes@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/26 17:34:45 by dximenes          #+#    #+#             */
/*   Updated: 2025/04/27 11:13:35 by dximenes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/ft_printf.h"

int ft_printnbr(int nbr)
{
	size_t	bytes;
	char	*string;

	string = ft_itoa(nbr);
	bytes = 0;
	while (string[bytes])
		bytes += ft_printchar(string[bytes]);
	free(string);
	return (bytes);
}
