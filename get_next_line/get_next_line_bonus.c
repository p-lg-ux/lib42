/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pgros <pgros@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/12 14:35:07 by pgros             #+#    #+#             */
/*   Updated: 2022/07/04 10:49:49 by pgros            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

void	clean_stash(t_stashlist **stash)
{
	int			i;
	char		*buffer;

	buffer = (*stash)->buffer;
	if ((*stash) != NULL && (*stash)->nl + 1 < (int)(*stash)->retval)
	{
		i = 0;
		while (buffer[(*stash)->nl + i + 1] != '\0')
		{
			buffer[i] = buffer[(*stash)->nl + i + 1];
			i++;
		}
		buffer[i] = '\0';
		(*stash)->retval = (*stash)->retval - (*stash)->nl - 1;
		(*stash)->nl = found_newline(buffer);
		return ;
	}
	lstclear_gnl(stash);
}

void	fill_str_and_free_stash(char *line_str, t_stashlist **stash)
{
	size_t		line_str_len;
	size_t		len_to_cat;
	t_stashlist	*temp;
	char		*line_str_end;

	line_str_len = 0;
	line_str[0] = '\0';
	line_str_end = line_str;
	temp = *stash;
	while (temp)
	{
		if (temp->nl < 0)
			len_to_cat = temp->retval;
		else
			len_to_cat = temp->nl + 1;
		line_str_len = ft_strlcat_gnl(line_str_end, temp->buffer,
				line_str_len, len_to_cat);
		line_str_end += len_to_cat;
		temp = temp->next;
		if ((*stash)->nl < 0)
		{
			free(*stash);
			*stash = temp;
		}
	}
}

void	init_read(int *stop_cdt, size_t *line_len, t_stashlist **last_node,
	t_stashlist *new_node)
{
	*line_len = 0;
	*stop_cdt = 0;
	*last_node = new_node;
	if (new_node != NULL)
	{
		*stop_cdt = ((new_node->nl >= 0) || (new_node->retval == 0));
		*line_len = new_node->retval;
	}
}

size_t	read_and_stash_line(int fd, t_stashlist **stash)
{
	t_stashlist	*new_node;
	t_stashlist	*last_node;
	int			stop_condition;
	size_t		line_len;

	new_node = *stash;
	init_read(&stop_condition, &line_len, &last_node, new_node);
	while (stop_condition != 1)
	{
		new_node = read_and_lstnew(fd);
		if (new_node == NULL)
			return (lstclear_gnl(stash));
		if (*stash == NULL)
			lstadd_back_gnl(stash, new_node);
		else
			lstadd_back_gnl(&last_node, new_node);
		stop_condition = ((new_node->nl >= 0) || (new_node->retval == 0));
		last_node = new_node;
		if (new_node->nl < 0)
			line_len += new_node->retval;
		else
			line_len += new_node->nl + 1;
	}
	return (line_len);
}

char	*get_next_line(int fd)
{
	static t_stashlist	*stash_tab[FOPEN_MAX] = {NULL};
	char				*line_str;
	size_t				line_len;
	t_stashlist			**stash;

	if (fd < 0 || BUFFER_SIZE <= 0 || read(fd, &line_str, 0) < 0)
		return (NULL);
	stash = &(stash_tab[fd]);
	line_len = read_and_stash_line(fd, stash);
	if (*stash == NULL || line_len == 0)
	{
		lstclear_gnl(stash);
		return (NULL);
	}
	line_str = malloc((line_len + 1) * sizeof(char));
	if (!line_str)
	{
		lstclear_gnl(stash);
		return (NULL);
	}
	fill_str_and_free_stash(line_str, stash);
	clean_stash(stash);
	return (line_str);
}
