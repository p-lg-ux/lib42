/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pgros <pgros@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/05 12:50:51 by pgros             #+#    #+#             */
/*   Updated: 2022/05/05 15:18:13 by pgros            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	size_t	len_little;
	size_t	len_big;
	size_t	i;

	len_little = ft_strlen(little);
	len_big = ft_strlen(big);
	if (len_little == 0)
		return ((char *)big);
	if (len_little > len || len_little > len_big)
		return (NULL);
	i = 0;
	while (i <= len - len_little && i <= len_big - len_little)
	{
		if (ft_strncmp(little, big + i, len_little) == 0)
			return ((char *)(big + i));
		i++;
	}
	return (NULL);
}
/*
#include <bsd/string.h>
#include <stdio.h>

int main(void)
{
	const char *largestring = "Foo Bar Baz";
    const char *smallstring = "Ba";
    char *ptr;
    char *ptr_test;

    ptr = strnstr(largestring, smallstring, 3);
	ptr_test = ft_strnstr(largestring, smallstring, 3);
	printf("%s %s\n", ptr, ptr_test);
	ptr = strnstr(largestring, "", 0);
	ptr_test = ft_strnstr(largestring, "", 0);
	printf("%s %s\n", ptr, ptr_test);

	return (0);
}
*/