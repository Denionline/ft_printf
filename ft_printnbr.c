/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printnbr.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dximenes <dximenes@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/26 17:34:45 by dximenes          #+#    #+#             */
/*   Updated: 2025/05/06 14:45:27 by dximenes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/ft_printf.h"

int	ft_printnbr(int nbr, t_flag *flags, int toverify)
{
	size_t	bytes;
	char	*string;
	int		i;

	bytes = 0;
	string = ft_itoa(nbr);
	if (!string)
		return (bytes);
	if (nbr < 0)
		flags->negative = TRUE;
	i = 0;
	if (toverify)
		bytes = ft_printflags(flags, string + flags->negative);
	else
		while (string[i])
			bytes += ft_printchar(string[i++], flags, FALSE);
	free(string);
	return (bytes);
}
