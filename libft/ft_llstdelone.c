/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_llstdelone.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pgros <pgros@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/11 14:53:37 by pgros             #+#    #+#             */
/*   Updated: 2022/07/11 15:05:56 by pgros            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_llstdelone(t_llist *lst, void (*del)(void *))
{
	if (!del || !lst)
		return ;
	del(lst->content);
	free(lst);
}