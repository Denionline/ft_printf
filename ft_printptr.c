/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printptr.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dximenes <dximenes@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/26 17:37:57 by dximenes          #+#    #+#             */
/*   Updated: 2025/05/03 09:30:42 by dximenes         ###   ########.fr       */
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

static int	fh_printhexa(uintptr_t n)
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
		buffer[size] = (char)hexa[n % 16];
		n /= 16;
	}
	bytes = ft_printstr(buffer);
	free(buffer);
	return (bytes);
}

int	ft_printptr(void *nbr)
{
	uintptr_t	addr;

	addr = (uintptr_t)nbr;
	if (addr == 0)
		return (ft_printstr("(nil)"));
	return (ft_printstr("0x") + fh_printhexa(addr));
}
