/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pgros <pgros@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/06 10:29:24 by pgros             #+#    #+#             */
/*   Updated: 2022/05/06 16:54:07 by pgros            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*substr;
	size_t	len_s;
	size_t	alloc_size;

	if (!s)
		return (NULL);
	len_s = ft_strlen(s);
	if (start > len_s)
	{
		substr = malloc(1 * sizeof(char));
		if (!substr)
			return (substr);
		*substr = '\0';
		return (substr);
	}
	if (len_s - start < len)
		alloc_size = len_s - start + 1;
	else
		alloc_size = len + 1;
	substr = malloc(alloc_size * sizeof(char));
	if (!substr)
		return (substr);
	ft_strlcpy(substr, s + start, len + 1);
	return (substr);
}
/*
#include <stdio.h>
int main(void)
{
	char *s = "tripouille";
	char *new;

	new = ft_substr(s, 100, 1);
	if (!new)
		printf("null\n");
	else
		printf ("%s\n%s\n", s, new);
	free(new);
	return (0);
}
*/