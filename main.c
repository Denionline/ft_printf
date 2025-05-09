/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dximenes <dximenes@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/23 12:33:25 by dximenes          #+#    #+#             */
/*   Updated: 2025/05/09 11:56:06 by dximenes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/ft_printf.h"

int	main(void)
{
	printf("\n------Test13------\n");
	printf("|%d|", printf("%07i", -54));
	printf("\n");
	printf("|%d|", ft_printf("%07i", -54));
	printf("\n------Test14------\n");
	printf("|%d|", printf("%08.5i", 34));
	printf("\n");
	printf("|%d|", ft_printf("%08.5i", 34));
	printf("\n------Test15------\n");
	printf("|%d|", printf("%010.5i", -216));
	printf("\n");
	printf("|%d|", ft_printf("%010.5i", -216));
	printf("\n------Test16------\n");
	printf("|%d|", printf("%08.5i", 0));
	printf("\n");
	printf("|%d|", ft_printf("%08.5i", 0));
	printf("\n------Test17------\n");
	printf("|%d|", printf("%08.3i", 8375));
	printf("\n");
	printf("|%d|", ft_printf("%08.3i", 8375));
	printf("\n------Test18------\n");
	printf("|%d|", printf("%08.3i", -8473));
	printf("\n");
	printf("|%d|", ft_printf("%08.3i", -8473));
	printf("\n------Test19------\n");
	printf("|%d|", printf("%.0i", 0));
	printf("\n");
	printf("|%d|", ft_printf("%.0i", 0));

	return (0);
}
