/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_llstadd_front.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pgros <pgros@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/11 14:26:20 by pgros             #+#    #+#             */
/*   Updated: 2022/07/11 19:23:45 by pgros            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_llstadd_front(t_llist **lst, t_llist *new)
{
	if (!lst || !new)
		return ;
	new->next = *lst;
	new->previous = NULL;
	if (*lst != NULL)
		(*lst)->previous = new;
	*lst = new;
}
