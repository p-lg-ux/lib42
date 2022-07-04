/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pgros <pgros@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/04 10:17:48 by pgros             #+#    #+#             */
/*   Updated: 2022/05/04 15:17:02 by pgros            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcpy(char *dst, const char *src, size_t size)
{
	size_t	i;

	i = 0;
	if (size == 0)
	{
		return (ft_strlen(src));
	}
	while (src[i] != '\0' && i < (size - 1))
	{
		dst[i] = src[i];
		i++;
	}
	dst[i] = '\0';
	return (ft_strlen(src));
}
/*
#include <bsd/string.h>
#include <stdio.h>
int main(void)
{
	size_t res;
	char dst[4] = "Bob";
	char *src = NULL;
	char dst_test[4] = "Bob";
	char *src_test = NULL;
	size_t n = 0;

	printf("ft_strlcpy :\n");
	printf("%s %s\n", dst_test, src_test);
	res = ft_strlcpy(dst_test, src_test, n);
	printf("%li %s %s\n", res, dst_test, src_test);

	printf("strlcpy :\n");
	printf("%s %s\n", dst, src);
	res = strlcpy(dst, src, n);
	printf("%li %s %s\n\n", res, dst, src);

	return (0);
}
*/