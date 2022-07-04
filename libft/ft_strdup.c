/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pgros <pgros@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/05 17:45:00 by pgros             #+#    #+#             */
/*   Updated: 2022/05/05 18:05:02 by pgros            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s)
{
	char	*new;
	size_t	len;

	len = ft_strlen(s);
	new = malloc((len + 1) * sizeof(char));
	if (!new)
		return (new);
	ft_strlcpy(new, s, len + 1);
	return (new);
}
/*
#include <stdio.h>
int main(void)
{
	char *n;
	char *s = "hello";
	
	n = strdup(s);
	printf("strdup :\n");
	if (!n)
		printf("null\n");
	else
		printf("%p : %s\n%p : %s\n", s, s, n, n);
	free(n);

	n = ft_strdup(s);
	printf("ft_strdup :\n");
	if (!n)
		printf("null\n");
	else
		printf("%p : %s\n%p : %s\n", s, s, n, n);
	free(n);
	return (0);
}
*/