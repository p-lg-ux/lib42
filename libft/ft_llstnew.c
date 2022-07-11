/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_llstnew.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pgros <pgros@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/11 14:23:09 by pgros             #+#    #+#             */
/*   Updated: 2022/07/11 15:06:33 by pgros            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_llist	*ft_llstnew(void *content)
{
	t_llist	*new_node;

	new_node = malloc(sizeof(t_list));
	if (!new_node)
		return (new_node);
	new_node->content = content;
	new_node->previous = NULL;
	new_node->next = NULL;
	return (new_node);
}
