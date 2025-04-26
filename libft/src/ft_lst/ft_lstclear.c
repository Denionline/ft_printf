/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dximenes <dximenes@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/12 13:53:36 by dximenes          #+#    #+#             */
/*   Updated: 2025/04/13 17:27:39 by dximenes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void*))
{
	t_list	*node;

	if (lst)
	{
		node = (*lst);
		while (node != NULL)
		{
			node = (*lst)->next;
			if (del)
				del((*lst)->content);
			free(*lst);
			(*lst) = node;
		}
		(*lst) = NULL;
	}
}
