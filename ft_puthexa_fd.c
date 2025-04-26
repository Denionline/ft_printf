/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_puthexa_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dximenes <dximenes@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/23 16:28:10 by dximenes          #+#    #+#             */
/*   Updated: 2025/04/24 17:03:51 by dximenes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_puthexa_fd(unsigned long long n, int c, int fd)
{
	const char	*hexa = "0123456789abcdef";

	if (n >= 16)
		ft_puthexa_fd((n / 16), c, fd);
	if (c == 'X')
		ft_putchar_fd((char)ft_toupper(hexa[n % 16]), fd);
	else
		ft_putchar_fd(hexa[n % 16], fd);
}