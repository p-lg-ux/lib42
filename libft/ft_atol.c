/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atol.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pgros <pgros@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/05 15:20:39 by pgros             #+#    #+#             */
/*   Updated: 2022/07/12 16:52:00 by pgros            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

long	ft_atol(const char *nptr)
{
	unsigned int	i;
	long			sign;
	long			nbr;

	i = 0;
	sign = 1;
	nbr = 0;
	while (nptr[i] != '\0'
		&& (nptr[i] == ' ' || (nptr[i] >= '\t' && nptr[i] <= '\r')))
		i++;
	if (nptr[i] != '\0' && (nptr[i] == '+' || nptr[i] == '-'))
	{
		if (nptr[i] == '-')
			sign = sign * -1;
		i++;
	}
	while (nptr[i] != '\0' && (nptr[i] >= '0' && nptr[i] <= '9'))
	{
		nbr = nbr * 10 + (nptr[i] - '0');
		i++;
	}
	return (nbr * sign);
}
/*
#include <stdio.h>
int	main(void)
{
	char *str1 = NULL;
	printf("%i %i\n", atoi(str1), ft_atoi(str1));
	return (0);
}
*/