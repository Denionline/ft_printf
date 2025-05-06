/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printuint.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dximenes <dximenes@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/27 11:07:21 by dximenes          #+#    #+#             */
/*   Updated: 2025/05/06 14:11:08 by dximenes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/ft_printf.h"

static size_t	ft_uintsize(unsigned int n)
{
	size_t	size;

	size = 1;
	while (n >= 10)
	{
		size++;
		n /= 10;
	}
	return (size);
}

int	ft_printuint(unsigned int n, t_flag *flags, int toverify)
{
	size_t	bytes;
	size_t	size;
	char	*string;

	size = ft_uintsize(n);
	string = (char *)malloc(size + 1);
	if (!string)
		return (0);
	string[size] = '\0';
	while (size--)
	{
		string[size] = (n % 10) + '0';
		n /= 10;
	}
	if (toverify)
		bytes = ft_printflags(flags, string);
	else
		bytes = ft_printstr(string, flags, FALSE);
	free(string);
	return (bytes);
}
