/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dximenes <dximenes@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/23 12:33:25 by dximenes          #+#    #+#             */
/*   Updated: 2025/05/07 17:01:43 by dximenes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/ft_printf.h"



int	main(void)
{
	// printf("\n------Teste7------\n");
	// printf("|%d|", printf("%.03s", NULL));
	// printf("\n");
	// printf("|%d|", ft_printf("%.03s", NULL));
	printf("\n------Teste8------\n");
	printf("|%d|", printf("%3.s", "s_hidden"));
	printf("\n");
	printf("|%d|", ft_printf("%3.s", "s_hidden"));
	printf("\n------Teste9------\n");
	printf("|%d|", printf("%10.s", "s_hidden"));
	printf("\n");
	printf("|%d|", ft_printf("%10.s", "s_hidden"));
	// printf("\n------Teste10------\n");
	// printf("|%d|", printf("%3.s", NULL));
	// printf("\n");
	// printf("|%d|", ft_printf("%3.s", NULL));
	// printf("\n------Teste11------\n");
	// printf("|%d|", printf("%10.s", NULL));
	// printf("\n");
	// printf("|%d|", ft_printf("%10.s", NULL));
	printf("\n------Teste12------\n");
	printf("|%d|", printf("%1.s", "\0"));
	printf("\n");
	printf("|%d|", ft_printf("%1.s", "\0"));
	printf("\n------Teste13------\n");
	printf("|%d|", printf("%2.s", "\0"));
	printf("\n");
	printf("|%d|", ft_printf("%2.s", "\0"));
	printf("\n------Teste14------\n");
	printf("|%d|", printf("%9.s", "\0"));
	printf("\n");
	printf("|%d|", ft_printf("%9.s", "\0"));
	printf("\n------Teste15------\n");
	printf("|%d|", printf("%-3.s", "s_hidden"));
	printf("\n");
	printf("|%d|", ft_printf("%-3.s", "s_hidden"));
	printf("\n------Teste16------\n");
	printf("|%d|", printf("%-8.s", "s_hidden"));
	printf("\n");
	printf("|%d|", ft_printf("%-8.s", "s_hidden"));
	// printf("\n------Teste17------\n");
	// printf("|%d|", printf("%-3.s", NULL));
	// printf("\n");
	// printf("|%d|", ft_printf("%-3.s", NULL));
	// printf("\n------Teste18------\n");
	// printf("|%d|", printf("%-8.s", NULL));
	// printf("\n");
	// printf("|%d|", ft_printf("%-8.s", NULL));
	printf("\n------Teste19------\n");
	printf("|%d|", printf("%-1.s", "\0"));
	printf("\n");
	printf("|%d|", ft_printf("%-1.s", "\0"));
	printf("\n-----Teste20------\n");
	printf("|%d|", printf("%-2.s", "\0"));
	printf("\n");
	printf("|%d|", ft_printf("%-2.s", "\0"));
	printf("\n");
	return (0);
}
