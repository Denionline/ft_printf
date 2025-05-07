/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printstr.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dximenes <dximenes@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/26 17:32:30 by dximenes          #+#    #+#             */
/*   Updated: 2025/05/07 14:49:48 by dximenes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/ft_printf.h"

int	ft_printstr(const char *str, t_flag *flags, int toverify)
{
	int	bytes;
	int	i;

	bytes = 0;
	if (!str)
		return (ft_printstr("(null)", flags, TRUE));
	if (toverify)
		return (ft_printflags(flags, str));
	i = 0;
	while (str[i])
		bytes += ft_printchar(str[i++], flags, FALSE);
	return (bytes);
}
