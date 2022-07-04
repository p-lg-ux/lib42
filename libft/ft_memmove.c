/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pgros <pgros@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/03 16:27:43 by pgros             #+#    #+#             */
/*   Updated: 2022/05/03 18:57:24 by pgros            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	unsigned char		*d;
	const unsigned char	*s;
	size_t				i;

	s = src;
	d = dest;
	i = 0;
	if ((dest == src && dest != 0) || n == 0)
		return (dest);
	if (d < s)
	{
		while (i < n)
		{
			d[i] = s[i];
			i++;
		}
		return (dest);
	}
	return (ft_memcpy(dest, src, n));
}
/*
#include <stdio.h>

int main(void)
{
	//int src[3] = {258, 896, 333};
	//int src_test[3] = {259, 897, 334};
	int dest[3];
	int *src;
	//int *dest;
	src = NULL;
	//dest = NULL;
	//int dest_test[3];

	//printf("%i %i %i\n", src[0], src[1], src[2]);
	//printf("%i %i %i\n", dest[0], dest[1], dest[2]);
	//printf("%i %i %i\n", src_test[0], src_test[1], src_test[2]);
	//printf("%i %i %i\n", dest_test[0], dest_test[1], dest_test[2]);
	ft_memmove(dest, src, 4);
	//printf("%i %i %i\n", src[0], src[1], src[2]);
	//printf("%i %i %i\n", dest[0], dest[1], dest[2]);

	return (0);
}
*/