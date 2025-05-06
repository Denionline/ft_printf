/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printchar.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dximenes <dximenes@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/26 17:31:21 by dximenes          #+#    #+#             */
/*   Updated: 2025/05/06 18:02:54 by dximenes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/ft_printf.h"

int	ft_printchar(int c, t_flag *flags, int toverify)
{
	if (toverify)
		return (ft_printflags(flags, (const char *)&c));
	return (write(1, &c, 1));
}
