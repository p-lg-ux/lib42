/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pgros <pgros@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/02 17:11:34 by pgros             #+#    #+#             */
/*   Updated: 2022/05/03 18:53:12 by pgros            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	unsigned char		*d;
	const unsigned char	*s;

	s = src;
	d = dest;
	if ((dest == src && dest != 0) || n == 0)
		return (dest);
	while (n--)
	{
		d[n] = s[n];
	}
	return (dest);
}
/*
#include <stdio.h>

int main(void)
{
	//int src[3] = {258, 896, 333};
	//int src_test[3] = {259, 897, 334};
	//int dest[3];
	int *src;
	int *dest;
	src = NULL;
	dest = NULL;
	//int dest_test[3];

	//printf("%i %i %i\n", src[0], src[1], src[2]);
	//printf("%i %i %i\n", dest[0], dest[1], dest[2]);
	//printf("%i %i %i\n", src_test[0], src_test[1], src_test[2]);
	//printf("%i %i %i\n", dest_test[0], dest_test[1], dest_test[2]);
	memcpy(dest, src, 0);
	//printf("%i %i %i\n", src[0], src[1], src[2]);
	//printf("%i %i %i\n", dest[0], dest[1], dest[2]);

	return (0);
}
*/