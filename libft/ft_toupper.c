/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_toupper.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pgros <pgros@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/04 16:52:26 by pgros             #+#    #+#             */
/*   Updated: 2022/05/04 16:58:26 by pgros            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_toupper(int c)
{
	if (c >= 'a' && c <= 'z')
		return (c - 32);
	return (c);
}
/*
#include <ctype.h>
#include <stdio.h>
int	main(void)
{
	int c;

	c = 400;
	printf("%i\n",toupper(c));
	printf("%i\n", ft_toupper(c));
	return (0);
}
*/