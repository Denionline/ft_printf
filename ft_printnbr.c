/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printnbr.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dximenes <dximenes@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/26 17:34:45 by dximenes          #+#    #+#             */
/*   Updated: 2025/05/11 19:07:34 by dximenes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_printnbr(int nbr)
{
	size_t	bytes;
	char	*string;
	int		i;

	string = ft_itoa(nbr);
	bytes = 0;
	if (!string)
		return (0);
	i = 0;
	while (string[i])
		bytes += ft_printchar(string[i++]);
	free(string);
	return (bytes);
}
