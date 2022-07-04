/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pgros <pgros@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/12 17:22:16 by pgros             #+#    #+#             */
/*   Updated: 2022/07/04 10:49:11 by pgros            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

size_t	ft_strlcat_gnl(char *dst_end, const char *src, size_t len_dest,
		size_t len_src)
{
	size_t	i;

	i = 0;
	while (*src && i < len_src)
	{
		*dst_end = *src;
		dst_end++;
		src++;
		i++;
	}
	*dst_end = '\0';
	return (len_dest + len_src);
}

int	found_newline(char *buffer)
{
	int	i;

	i = 0;
	while (buffer[i] != '\0' && i < BUFFER_SIZE + 1)
	{
		if (buffer[i] == '\n')
			return (i);
		i++;
	}
	return (-1);
}

t_stashlist	*read_and_lstnew(int fd)
{
	t_stashlist	*new;

	new = malloc(sizeof(t_stashlist));
	if (!new)
		return (NULL);
	new->next = NULL;
	new->retval = read(fd, new->buffer, BUFFER_SIZE);
	if (new->retval < 0)
	{
		free(new);
		return (NULL);
	}
	(new->buffer)[new->retval] = '\0';
	new->nl = found_newline(new->buffer);
	return (new);
}

void	lstadd_back_gnl(t_stashlist **lst, t_stashlist *new)
{
	t_stashlist	*last;

	if (!lst || !new)
		return ;
	last = *lst;
	while (last && last->next)
		last = last->next;
	if (last == NULL)
	{
		*lst = new;
		return ;
	}
	last->next = new;
	return ;
}

int	lstclear_gnl(t_stashlist **lst)
{
	t_stashlist	*next;

	if (!lst || !(*lst))
		return (0);
	next = (*lst)->next;
	while (next)
	{
		free(*lst);
		*lst = next;
		next = next->next;
	}
	free(*lst);
	*lst = NULL;
	return (0);
}
