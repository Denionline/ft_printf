/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printptr.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dximenes <dximenes@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/26 17:37:57 by dximenes          #+#    #+#             */
/*   Updated: 2025/05/04 20:40:34 by dximenes         ###   ########.fr       */
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

static int	fh_printhexa(uintptr_t n, t_flag *flags)
{
	const char	*hexa = "0123456789abcdef";
	size_t		bytes;
	size_t		size;
	char		*buff;

	size = fh_sizehexa(n);
	buff = (char *)malloc(size + 1);
	if (!buff)
		return (0);
	buff[size] = '\0';
	while (size--)
	{
		buff[size] = (char)hexa[n % 16];
		n /= 16;
	}
	bytes = ft_printstr(buff, flags);
	free(buff);
	return (bytes);
}

int	ft_printptr(void *nbr, t_flag *flags)
{
	uintptr_t	addr;

	addr = (uintptr_t)nbr;
	if (addr == 0)
		return (ft_printstr("(nil)", flags));
	flags->hexa = 2;
	return (fh_printhexa(addr, flags));
}
