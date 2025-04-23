/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dximenes <dximenes@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/23 12:33:25 by dximenes          #+#    #+#             */
/*   Updated: 2025/04/23 18:31:30 by dximenes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	main(void) {
	ft_printf("String      => [%s] vs ", "Hello");
	printf("[%s]\n", "Hello");
	ft_printf("Char        => [%c] vs ", 'K');
	printf("[%c]\n", 'K');
	ft_printf("Decimal     => [%d] vs ", 42);
	printf("[%d]\n", 42);
	ft_printf("Integer     => [%i] vs ", 42);
	printf("[%i]\n", 42);
	ft_printf("Unsigned    => [%u] vs ", 424242424);
	printf("[%u]\n", 424242424);
	ft_printf("Upper Hexa  => [%x] vs ", 42);
	printf("[%x]\n", 42);
	ft_printf("Lower Hexa  => [%X] vs ", 42);
	printf("[%X]\n", 42);
	ft_printf("Percent     => [%%] vs ");
	printf("[%%]\n");
	int	n = 10;
	int	*ptr = &n;
	ft_printf("Pointer     => [%p] vs ", ptr);
	printf("[%p]\n", ptr);
}

// %c
// %s
// %p
// %d
// %i
// %u
// %x
// %X
// %%