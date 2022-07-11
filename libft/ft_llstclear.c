/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_llstclear.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pgros <pgros@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/11 14:57:21 by pgros             #+#    #+#             */
/*   Updated: 2022/07/11 15:05:52 by pgros            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_llstclear(t_llist **lst, void (*del)(void *))
{
	t_llist	*next;

	if (!lst || !del || !(*lst))
		return ;
	next = (*lst)->next;
	while (next)
	{
		ft_llstdelone(*lst, del);
		*lst = next;
		next = next->next;
	}
	ft_llstdelone(*lst, del);
	*lst = NULL;
}
