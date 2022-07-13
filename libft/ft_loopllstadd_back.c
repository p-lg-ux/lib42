/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_loopllstadd_back.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pgros <pgros@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/11 14:37:31 by pgros             #+#    #+#             */
/*   Updated: 2022/07/13 15:35:24 by pgros            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_loopllstadd_back(t_llist **lst, t_llist *new)
{
	t_llist	*last;

	if (!lst || !new)
		return ;
	if (*lst == NULL)
		*lst = new;
	else
	{
		last = ft_loopllstlast(*lst);
		ft_loopllstadd_front(&last, new);
	}
}
