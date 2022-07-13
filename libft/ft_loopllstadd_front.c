/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_loopllstadd_front.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pgros <pgros@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/11 14:26:20 by pgros             #+#    #+#             */
/*   Updated: 2022/07/13 15:28:15 by pgros            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_loopllstadd_front(t_llist **lst, t_llist *new)
{
	t_llist	*last;
	t_llist	*head;

	if (!lst || !new)
		return ;
	if (*lst == NULL)
		*lst = new;
	else
	{
		head = *lst;
		last = ft_loopllstlast(head);
		last->next = new;
		head->previous = new;
		new->previous = last;
		new->next = head;
		*lst = new;
	}
}
