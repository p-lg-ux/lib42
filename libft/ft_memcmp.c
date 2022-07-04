/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pgros <pgros@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/05 12:36:41 by pgros             #+#    #+#             */
/*   Updated: 2022/05/05 12:46:06 by pgros            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	size_t				i;
	const unsigned char	*p1;
	const unsigned char	*p2;

	p1 = s1;
	p2 = s2;
	i = 0;
	if (n == 0)
		return (0);
	while (i < n - 1 && p1[i] == p2[i])
		i += 1;
	return ((unsigned char)p1[i] - (unsigned char)p2[i]);
}
/*
#include <stdio.h>
int	main(void)
{
	int str1[3] = {100, 200, 300};
	int str2[3] = {100, 200, 896};
	//str2[3] = 200;

	//printf("%s %s\n", str1, str2);
	//printf("%i %i\n", (int)str1[3], (int)str2[3]);

	printf("%i\n",memcmp(str1,str2,6));
	printf("%i\n",memcmp(str1,str2,10));
	printf("%i\n",memcmp(str1,str2,0));

	printf("%i\n",ft_memcmp(str1,str2,6));
	printf("%i\n",ft_memcmp(str1,str2,10));
	printf("%i\n",ft_memcmp(str1,str2,0));

	return (0);
}
*/