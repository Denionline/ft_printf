/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printhexa.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dximenes <dximenes@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/23 16:28:10 by dximenes          #+#    #+#             */
/*   Updated: 2025/05/02 17:36:02 by dximenes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/ft_printf.h"

static size_t	fh_sizehexa(uintptr_t nbr)
{
	size_t	i;

	i = 1;
	while (nbr >= 16)
	{
		nbr /= 16;
		i++;
	}
	return (i);
}

int	ft_printhexa(unsigned int n, int c)
{
	const char	*hexa = "0123456789abcdef";
	size_t		bytes;
	size_t		size;
	char		*buffer;

	size = fh_sizehexa(n);
	buffer = (char *)malloc(size + 1);
	if (!buffer)
		return (0);
	buffer[size] = '\0';
	while (size--)
	{
		if (c == 'X')
			buffer[size] = ft_toupper(hexa[n % 16]);
		else
			buffer[size] = hexa[n % 16];
		n /= 16;
	}
	bytes = ft_printstr(buffer);
	free(buffer);
	return (bytes);
}
