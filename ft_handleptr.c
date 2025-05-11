/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_handleptr.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dximenes <dximenes@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/26 17:37:57 by dximenes          #+#    #+#             */
/*   Updated: 2025/05/11 10:16:46 by dximenes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/ft_printf.h"

static size_t	fh_sizeptr(uintptr_t nbr)
{
	size_t	i;

	i = 0;
	while (++i && nbr >= 16)
		nbr /= 16;
	return (i);
}

char	*ft_handleptr(void *addr)
{
	uintptr_t	nbr;
	size_t		size;
	char		*buff;
	char		*newaddr;

	nbr = (uintptr_t)addr;
	if (nbr == 0)
		return (ft_strdup("(nil)"));
	size = fh_sizeptr(nbr);
	buff = (char *)malloc(size + 1);
	if (!buff)
		return (NULL);
	buff[size] = '\0';
	while (size--)
	{
		buff[size] = "0123456789abcdef"[nbr % 16];
		nbr /= 16;
	}
	newaddr = ft_strjoin("0x", buff);
	free(buff);
	return (newaddr);
}
