/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dximenes <dximenes@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/23 10:42:07 by dximenes          #+#    #+#             */
/*   Updated: 2025/05/04 18:09:57 by dximenes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H

# define FT_PRINTF_H

# include <stdlib.h>
# include <limits.h>
# include <stdio.h>
# include <stdint.h>
# include <stdarg.h>
# include "../libft/include/libft.h"

typedef struct s_flag
{
	int		plus;
	int		minus;
	int		digit;
	int		point;
	int		hash;
	int		hexa;
	int		pad;
	int		width;
	int		precision;
	char	*format;
}	t_flag;

int	ft_printf(const char *format, ...);
int	ft_printchar(int c, t_flag *flags);
int	ft_printhexa(unsigned int n, int c, t_flag *flags);
int	ft_printstr(const char *str, t_flag *flags);
int	ft_printnbr(int nbr, t_flag *flags);
int	ft_printptr(void *nbr, t_flag *flags);
int	ft_printuint(unsigned int n, t_flag *flags);
size_t	ft_printflags(t_flag *flags, const char *string);

#endif
