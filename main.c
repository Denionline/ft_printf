/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dximenes <dximenes@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/23 12:33:25 by dximenes          #+#    #+#             */
/*   Updated: 2025/05/08 17:12:52 by dximenes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/ft_printf.h"

int	main(void)
{
	printf("\n------Test10------\n");
	printf("|%d|", printf("%3.1s", NULL));
	printf("\n");
	printf("|%d|", ft_printf("%3.1s", NULL));
	printf("\n------Test11------\n");
	printf("|%d|", printf("%9.1s", NULL));
	printf("\n");
	printf("|%d|", ft_printf("%9.1s", NULL));
	printf("\n------Test12------\n");
	printf("|%d|", printf("%-3.1s", NULL));
	printf("\n");
	printf("|%d|", ft_printf("%-3.1s", NULL));
	printf("\n------Test13------\n");
	printf("|%d|", printf("%-9.1s", NULL));
	printf("\n");
	printf("|%d|", ft_printf("%-9.1s", NULL));
	printf("\n------Test14------\n");
	printf("|%d|", printf("%-3.1s", "\0"));
	printf("\n");
	printf("|%d|", ft_printf("%-3.1s", "\0"));
	printf("\n------Test15------\n");
	printf("|%d|", printf("%-6.1s", "\0"));
	printf("\n");
	printf("|%d|", ft_printf("%-6.1s", "\0"));
	printf("\n------Test16------\n");
	printf("|%d|", printf("%3.6s", "\0"));
	printf("\n");
	printf("|%d|", ft_printf("%3.6s", "\0"));
	printf("\n------Test17------\n");
	printf("|%d|", printf("%6.6s", "\0"));
	printf("\n");
	printf("|%d|", ft_printf("%6.6s", "\0"));
	printf("\n------Test18------\n");
	printf("|%d|", printf("%.5i", 2));
	printf("\n");
	printf("|%d|", ft_printf("%.5i", 2));
	printf("\n------Test19------\n");
	printf("|%d|", printf("%.6i", -3));
	printf("\n");
	printf("|%d|", ft_printf("%.6i", -3));
	printf("\n------Test20------\n");
	printf("|%d|", printf("%.3i", 0));
	printf("\n");
	printf("|%d|", ft_printf("%.3i", 0));
	return (0);
}
