/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pgros <pgros@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/02 15:06:10 by pgros             #+#    #+#             */
/*   Updated: 2022/05/03 18:35:18 by pgros            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlen(const char *s)
{
	size_t	len;

	len = 0;
	while (s[len] != 0)
		len++;
	return (len);
}
/* TESTS OK
#include <stdio.h>
int main(void)
{
	char    s[20] = "Hello";
	char    s_empty[20] = "";
	char    *s_null;

	s_null = 0;

	printf("%li\n", strlen(s));
	printf("%li\n", ft_strlen(s));
	printf("%li\n", strlen(s_empty));
	printf("%li\n", ft_strlen(s_empty));
	printf("%li\n", ft_strlen(s_null));
	printf("%li\n", strlen(s_null));
	return (0);
}
*/