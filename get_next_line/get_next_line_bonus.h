/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.h                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pgros <pgros@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/12 12:58:18 by pgros             #+#    #+#             */
/*   Updated: 2022/07/04 10:49:19 by pgros            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_BONUS_H
# define GET_NEXT_LINE_BONUS_H

# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 5
# endif

struct	s_stashlist
{
	char				buffer[BUFFER_SIZE + 1];
	ssize_t				retval;
	int					nl;
	struct s_stashlist	*next;
};

typedef struct s_stashlist	t_stashlist;

char		*get_next_line(int fd);
size_t		read_and_stash_line(int fd, t_stashlist **stash);
void		clean_stash(t_stashlist **stash);
t_stashlist	*read_and_lstnew(int fd);
void		lstadd_back_gnl(t_stashlist **lst, t_stashlist *new);
int			lstclear_gnl(t_stashlist **lst);
int			found_newline(char *buffer);
void		fill_str_and_free_stash(char *line_str, t_stashlist **stash);
size_t		ft_strlcat_gnl(char *dst, const char *src, size_t len_dest,
				size_t len_src);
void		init_read(int *stop_cdt, size_t *line_len, t_stashlist **last_node,
				t_stashlist *new_node);

#endif