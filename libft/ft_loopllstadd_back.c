/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_loopllstadd_back.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pgros <pgros@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/11 14:37:31 by pgros             #+#    #+#             */
/*   Updated: 2022/07/13 15:53:21 by pgros            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_loopllstadd_back(t_llist **lst, t_llist *new)
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
		last = ft_loopllstlast(*lst);
		last->next = new;
		head->previous = new;
		new->next = head;
		new->previous = head;
	}
}
