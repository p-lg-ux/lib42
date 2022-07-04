/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tolower.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pgros <pgros@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/04 16:58:51 by pgros             #+#    #+#             */
/*   Updated: 2022/05/04 17:01:10 by pgros            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_tolower(int c)
{
	if (c >= 'A' && c <= 'Z')
		return (c + 32);
	return (c);
}
/*
#include <ctype.h>
#include <stdio.h>
int	main(void)
{
	int c;

	c = 'W';
	printf("%c\n",tolower(c));
	printf("%c\n", ft_tolower(c));
	return (0);
}
*/