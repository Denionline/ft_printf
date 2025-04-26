/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dximenes <dximenes@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/23 10:42:07 by dximenes          #+#    #+#             */
/*   Updated: 2025/04/26 17:43:35 by dximenes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H

# define FT_PRINTF_H

# include <stdio.h>
# include <stdint.h>
# include <stdarg.h>
# include "../libft/include/libft.h"

int	ft_printf(const char *format, ...);
int	ft_printhexa(unsigned long long n, int c);
int ft_printstr(const char *str);
int ft_printchar(int c);
int ft_printnbr(int  nbr);

#endif