/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstsize_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pgros <pgros@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/10 10:50:13 by pgros             #+#    #+#             */
/*   Updated: 2022/05/10 10:55:38 by pgros            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_lstsize(t_list *lst)
{
	int	nb_nodes;

	nb_nodes = 0;
	while (lst)
	{
		nb_nodes++;
		lst = lst->next;
	}
	return (nb_nodes);
}
