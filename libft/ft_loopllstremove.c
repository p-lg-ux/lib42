/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_loopllstremove.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pgros <pgros@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/11 14:23:09 by pgros             #+#    #+#             */
/*   Updated: 2022/07/13 17:04:04 by pgros            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_llist	*ft_loopllstremove(t_llist **lst, t_llist *node)
{
	t_llist	*previous_node;
	t_llist	*next_node;

	if (lst == NULL || *lst == NULL || node == NULL)
		return (NULL);
	if (*lst == (*lst)->next && *lst == node)
	{
		*lst = NULL;
		return (node);
	}
	previous_node = node->previous;
	next_node = node->next;
	previous_node->next = next_node;
	next_node->previous = previous_node;
	if (node == *lst)
		*lst = (*lst)->next;
	node->previous = node;
	node->next = node;
	return (node);
}
