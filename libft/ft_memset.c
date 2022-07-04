/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pgros <pgros@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/02 15:15:57 by pgros             #+#    #+#             */
/*   Updated: 2022/05/03 18:46:29 by pgros            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *s, int c, size_t n)
{
	size_t			i;
	unsigned char	*ptr;

	ptr = s;
	i = 0;
	while (i < n)
	{
		*(ptr + i) = c;
		i++;
	}
	return (s);
}
/*
#include <stdio.h>
int main(void)
{
	char    s[20] = "Hello";
	char    t[20] = "Hello";
	char    *s_null;

	s_null = 0;

	printf("%s\n", (char *)memset(s+2, 239, 2));
	printf("%s\n", (char *)ft_memset(t+2, 239, 2));
	printf("%s\n", (char *)ft_memset(s_null, '.', 2));
	printf("%s\n", (char *)memset(s_null, '.', 2));
	
	return (0);
}
*/