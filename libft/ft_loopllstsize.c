/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_loopllstsize.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pgros <pgros@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/11 15:03:10 by pgros             #+#    #+#             */
/*   Updated: 2022/07/13 15:41:29 by pgros            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_loopllstsize(t_llist *lst)
{
	t_llist	*head;
	int		nb_nodes;

	if (lst == NULL)
		return (0);
	else
	{
		head = lst;
		nb_nodes = 1;
		lst = lst->next;
		while (lst != head)
		{
			nb_nodes++;
			lst = lst->next;
		}
		return (nb_nodes);
	}
}
