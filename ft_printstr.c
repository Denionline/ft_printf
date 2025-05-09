/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printstr.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dximenes <dximenes@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/26 17:32:30 by dximenes          #+#    #+#             */
/*   Updated: 2025/05/09 10:02:21 by dximenes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/ft_printf.h"

int	ft_printstr(const char *str, t_flag *flags, int toverify)
{
	int	bytes;
	int	i;
	int	lstr;

	bytes = 0;
	if (!str)
	{
		flags->null = TRUE;
		return (ft_printstr("(null)", flags, TRUE));
	}
	lstr = ft_strlen(str);
	if (toverify)
		return (ft_printflags(flags, str));
	i = 0;
	while (i < lstr)
		bytes += ft_printchar(str[i++], flags, FALSE);
	return (bytes);
}
