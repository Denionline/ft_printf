/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_handlenbr.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dximenes <dximenes@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/26 17:34:45 by dximenes          #+#    #+#             */
/*   Updated: 2025/05/11 19:07:34 by dximenes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*ft_handlenbr(int nbr, t_flag *f)
{
	char	*string;

	string = ft_itoa(nbr);
	if (string[0] == '0' && f->precision == 0 && f->dot)
		string[0] = '\0';
	if (!string)
		return (NULL);
	if (nbr < 0)
		f->negative = TRUE;
	return (string + f->negative);
}
