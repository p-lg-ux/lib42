/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pgros <pgros@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/06 11:30:17 by pgros             #+#    #+#             */
/*   Updated: 2022/05/06 15:21:10 by pgros            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static	int	ft_is_in_set(char c, char const *set)
{
	int	i;

	i = 0;
	while (set[i] != '\0')
	{
		if (set[i] == c)
			return (1);
		i++;
	}
	return (0);
}

static	unsigned int	ft_startpos(char const *s1, char const *set)
{
	unsigned int	start;

	start = 0;
	while (s1[start] != '\0' && ft_is_in_set(s1[start], set))
		start++;
	return (start);
}

static	size_t	ft_nb_totrim(char const *s1, char const *set)
{
	size_t	nb;
	int		i;
	size_t	len_s1;

	len_s1 = ft_strlen(s1);
	nb = ft_startpos(s1, set);
	i = len_s1 - 1;
	if (nb < len_s1)
	{
		while (i >= 0 && ft_is_in_set(s1[i], set))
		{
			nb++;
			i--;
		}
	}
	return (nb);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	char			*new;
	size_t			len;
	unsigned int	start;

	if (!s1 || !set)
		return (NULL);
	start = ft_startpos(s1, set);
	len = ft_strlen(s1) - ft_nb_totrim(s1, set);
	new = ft_substr(s1, start, len);
	return (new);
}
/*
#include <stdio.h>
int	main(void)
{
	char	*s = "aahellosaa b";
	char	*set = "abc";
	char	*new;

	new = ft_strtrim(s, set);
	if (!new)
		printf("null\n");
	else
		printf("%s\n", ft_strtrim(s, set));
	free(new);
	return (0);
}
*/