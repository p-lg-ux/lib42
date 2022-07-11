/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_llstadd_back.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pgros <pgros@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/11 14:37:31 by pgros             #+#    #+#             */
/*   Updated: 2022/07/11 15:05:45 by pgros            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_llstadd_back(t_llist **lst, t_llist *new)
{
	t_llist	*last;

	if (!lst || !new)
		return ;
	last = ft_llstlast(*lst);
	if (!last)
	{
		ft_llstadd_front(lst, new);
		return ;
	}
	last->next = new;
	new->previous = last;
	return ;
}
