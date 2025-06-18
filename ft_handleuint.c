/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_handleuint.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dximenes <dximenes@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/27 11:07:21 by dximenes          #+#    #+#             */
/*   Updated: 2025/05/11 19:07:34 by dximenes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static size_t	ft_uintsize(unsigned int n)
{
	size_t	size;

	size = 0;
	while (++size && n >= 10)
		n /= 10;
	return (size);
}

char	*ft_handleuint(unsigned int n, t_flag *f)
{
	size_t	size;
	char	*string;

	size = ft_uintsize(n);
	string = (char *)malloc(size + 1);
	if (!string)
		return (NULL);
	string[size] = '\0';
	while (size--)
	{
		string[size] = (n % 10) + '0';
		n /= 10;
	}
	if (string[0] == '0' && f->precision == 0 && f->dot)
		string[0] = '\0';
	return (string);
}
