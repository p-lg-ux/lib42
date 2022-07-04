/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pgros <pgros@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/05 12:12:54 by pgros             #+#    #+#             */
/*   Updated: 2022/05/05 12:23:43 by pgros            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	const unsigned char	*ptr;

	c = (unsigned char) c;
	ptr = s;
	while (n--)
	{
		if (*ptr == c)
			return ((void *)ptr);
		ptr++;
	}
	return (NULL);
}
/*
#include <stdio.h>
int main(void)
{
	char str[10] = "hellol";
	char *s;
	s = NULL;

	printf("%s\n\n", str);
	printf("%s\n", (char *)memchr(str, 111, 8));
	printf("%s\n", (char *)ft_memchr(str, 111, 8));
	printf("%p\n", memchr(str, 111, 3));
	printf("%p\n", ft_memchr(str, 111, 3));
	printf("%p\n", memchr(str, 111, 0));
	printf("%p\n", ft_memchr(str, 111, 0));
	printf("%p\n", memchr(str, 65, 8));
	printf("%p\n", ft_memchr(str, 65, 8));
	printf("%p\n", ft_memchr(s, 0, 8));
	printf("%p\n", memchr(s, 0, 8));
	return (0);
}
*/