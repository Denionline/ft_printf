/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printhexa.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dximenes <dximenes@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/23 16:28:10 by dximenes          #+#    #+#             */
/*   Updated: 2025/05/06 14:11:04 by dximenes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/ft_printf.h"

static size_t	fh_sizehexa(unsigned int nbr)
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

int	ft_printhexa(unsigned int n, int c, t_flag *flags, int toverify)
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
		if (c == 'X')
			buff[size] = ft_toupper(hexa[n % 16]);
		else
			buff[size] = hexa[n % 16];
		n /= 16;
	}
	if (toverify)
		bytes = ft_printflags(flags, buff);
	else
		bytes = ft_printstr(buff, flags, FALSE);
	free(buff);
	return (bytes);
}
