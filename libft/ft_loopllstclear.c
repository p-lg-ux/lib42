/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_loopllstclear.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pgros <pgros@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/11 14:57:21 by pgros             #+#    #+#             */
/*   Updated: 2022/07/13 15:01:50 by pgros            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_loopllstclear(t_llist **lst, void (*del)(void *))
{
	t_llist	*next;
	t_llist	*head;

	if (!lst || !del || !(*lst))
		return ;
	head = *lst;
	next = (*lst)->next;
	while (next != head)
	{
		ft_llstdelone(*lst, del);
		*lst = next;
		next = next->next;
	}
	ft_llstdelone(*lst, del);
	*lst = NULL;
}
