/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pgros <pgros@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/05 11:23:25 by pgros             #+#    #+#             */
/*   Updated: 2022/05/05 16:55:15 by pgros            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t	i;

	i = 0;
	if (n == 0)
		return (0);
	while (s1[i] && i < n - 1 && s1[i] == s2[i])
		i += 1;
	return ((unsigned char)s1[i] - (unsigned char)s2[i]);
}
/*
#include <stdio.h>
int	main(void)
{
	char *str1 = NULL;
	char *str2 = NULL;
	//str2[3] = 200;

	//printf("%s %s\n", str1, str2);
	//printf("%i %i\n", (int)str1[3], (int)str2[3]);

	printf("%i\n",ft_strncmp(str1,str2,3));
	printf("%i\n",ft_strncmp(str1,str2,5));

	printf("%i\n",strncmp(str1,str2,3));
	printf("%i\n",strncmp(str1,str2,5));

	return 0;
}
*/