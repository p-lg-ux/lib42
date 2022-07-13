/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_loopllstnew.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pgros <pgros@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/11 14:23:09 by pgros             #+#    #+#             */
/*   Updated: 2022/07/13 15:09:33 by pgros            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_llist	*ft_loopllstnew(void *content)
{
	t_llist	*new_node;

	new_node = malloc(sizeof(t_llist));
	if (!new_node)
		return (new_node);
	new_node->content = content;
	new_node->previous = new_node;
	new_node->next = new_node;
	return (new_node);
}
