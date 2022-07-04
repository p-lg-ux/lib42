/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pgros <pgros@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/04 12:53:17 by pgros             #+#    #+#             */
/*   Updated: 2022/05/04 16:41:51 by pgros            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	i;
	size_t	len_dest;
	size_t	len_src;

	len_dest = ft_strlen(dst);
	len_src = ft_strlen(src);
	i = 0;
	if (size <= len_dest)
	{
		return (len_src + size);
	}
	while (*dst)
	{
		dst++;
	}
	while (*src && i < (size - len_dest - 1))
	{
		*dst = *src;
		dst++;
		src++;
		i++;
	}
	*dst = '\0';
	return (len_dest + len_src);
}
/*
#include <bsd/string.h>
#include <stdio.h>
int main(void)
{
	size_t res;
	char *dst= NULL;
	char *src = NULL;
	char *dst_test = NULL;
	char *src_test= NULL;
	size_t n = 2;

	printf("strlcat :\n");
	printf("%s %s\n", dst, src);
	res = strlcat(dst, src, n);
	printf("%li %s %s\n\n", res, dst, src);
	
	printf("ft_strlcat :\n");
	printf("%s %s\n", dst_test, src_test);
	res = ft_strlcat(dst_test, src_test, n);
	printf("%li %s %s\n\n", res, dst_test, src_test);

	return (0);
}
*/