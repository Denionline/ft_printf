/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dximenes <dximenes@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/23 10:42:07 by dximenes          #+#    #+#             */
/*   Updated: 2025/05/08 12:09:18 by dximenes         ###   ########.fr       */
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

# define TRUE 1
# define FALSE 0

typedef struct s_flag
{
	int		plus;
	int		minus;
	int		digit;
	int		point;
	int		hash;
	int		hexa;
	int		negative;
	int		pad;
	int		width;
	int		prec;
	int		symbol;
	int		exist;
	char	*format;
}	t_flag;

int		ft_printf(const char *format, ...);
size_t	ft_printflags(t_flag *flags, const char *string);

int		ft_printchar(int c, t_flag *flags, int toverify);
int		ft_printhexa(unsigned int n, int c, t_flag *flags, int toverify);
int		ft_printstr(const char *str, t_flag *flags, int toverify);
int		ft_printnbr(int nbr, t_flag *flags, int toverify);
int		ft_printptr(void *nbr, t_flag *flags);
int		ft_printuint(unsigned int n, t_flag *flags, int toverify);

#endif
