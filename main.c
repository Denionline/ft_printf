/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dximenes <dximenes@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/23 12:33:25 by dximenes          #+#    #+#             */
/*   Updated: 2025/05/04 22:44:49 by dximenes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/ft_printf.h"

int main(void) {
	int val;
	int prec;

	// Exemplo 1: valor positivo
	val = 42;
	prec = 5;
	printf("Original:    |%.*d|\n", prec, val);
	ft_printf("ft_printf:   |%.*d|\n", prec, val);

	// Exemplo 2: valor zero
	val = 0;
	prec = 3;
	printf("Original:    |%.*d|\n", prec, val);
	ft_printf("ft_printf:   |%.*d|\n", prec, val);

	// Exemplo 3: valor negativo
	val = -7;
	prec = 4;
	printf("Original:    |%.*d|\n", prec, val);
	ft_printf("ft_printf:   |%.*d|\n", prec, val);

	return 0;
}

// '+'
// '-'
// '0'
// '.'
// '#'
// '_'
// ft_strchr("cspdiuxX%", *format)