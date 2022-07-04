/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_striteri.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pgros <pgros@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/09 14:20:04 by pgros             #+#    #+#             */
/*   Updated: 2022/05/09 15:17:27 by pgros            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_striteri(char *s, void (*f)(unsigned int, char*))
{
	unsigned int	i;

	if (!s || !f)
		return ;
	i = 0;
	while (s[i] != '\0')
	{
		f(i, s + i);
		i++;
	}
}
/*
#include <stdio.h>
void	ft_toupper_test(unsigned int i, char *c)
{
	if (*c >= 'a' && *c <= 'z')
		*c -= 32;
	i = (size_t)i;
	return;
}

void
iter(unsigned int i, char * s) {
	*s += i;
}

int	main(void)
{
	char	str[] = "Hello les Amis 55!";
	char	str2[] = "0000000000";

	ft_striteri(str, &ft_toupper_test);
	printf("%s\n", str);
	ft_striteri(str2, &iter);
	printf("%s\n", str2);
	return (0);
}
*/