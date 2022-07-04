/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pgros <pgros@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/10 14:32:57 by pgros             #+#    #+#             */
/*   Updated: 2022/05/10 15:52:31 by pgros            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void *))
{
	t_list	*next;

	if (!lst || !del || !(*lst))
		return ;
	next = (*lst)->next;
	while (next)
	{
		ft_lstdelone(*lst, del);
		*lst = next;
		next = next->next;
	}
	ft_lstdelone(*lst, del);
	*lst = NULL;
}
