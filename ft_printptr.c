/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printptr.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dximenes <dximenes@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/26 17:37:57 by dximenes          #+#    #+#             */
/*   Updated: 2025/05/01 10:43:47 by dximenes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/ft_printf.h"

static size_t	fh_getsizehexa(uintptr_t nbr)
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

static char	*fh_printllhexa(uintptr_t n)
{
	const char	*hexa = "0123456789abcdef";
	size_t		size;
	char		*buffer;

	size = fh_getsizehexa(n);
	buffer = (char *)malloc(size + 1);
	if (!buffer)
		return (NULL);
	buffer[size] = '\0';
	while (size--)
	{
		buffer[size] = (char)hexa[n & 0xF];
		n >>= 4;
	}
	return (buffer);
}

int	ft_printptr(void *nbr)
{
	uintptr_t	addr;
	size_t		bytes;
	char		*str;

	addr = (uintptr_t)nbr;
	if (addr == 0)
		return (ft_printstr("(nil)"));
	bytes = ft_printstr("0x");
	str = fh_printllhexa(addr);
	bytes += ft_printstr(str);
	free(str);
	return (bytes);
}
