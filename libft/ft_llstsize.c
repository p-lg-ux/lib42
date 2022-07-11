/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_llstsize.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pgros <pgros@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/11 15:03:10 by pgros             #+#    #+#             */
/*   Updated: 2022/07/11 15:06:09 by pgros            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_llstsize(t_llist *lst)
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
