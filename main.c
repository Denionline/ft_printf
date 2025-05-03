/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dximenes <dximenes@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/23 12:33:25 by dximenes          #+#    #+#             */
/*   Updated: 2025/05/02 18:50:51 by dximenes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/ft_printf.h"

int main(void)
{
	ft_printf("Preceding with blanks |%010d|\n", 1977);
	// printf("Preceding with zeros: %06x \n", 9197);
	// printf("floats: %4.2f %+.0e %E \n", 3.1416, 3.1416, 3.1416);
	// printf("Width trick: %*d \n", 5, 10);
	// printf("%s \n", "A string");
	// printf("=> %d %x %o %#x %#o \n", 100, 100, 100, 100, 100);
	return 0;
}
