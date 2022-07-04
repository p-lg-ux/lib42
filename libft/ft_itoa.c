/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pgros <pgros@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/07 14:48:02 by pgros             #+#    #+#             */
/*   Updated: 2022/05/09 13:40:19 by pgros            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static	int	ft_give_len(int n)
{
	int		i;
	int		power;
	int		sign;
	long	nb;

	sign = 0;
	i = 1;
	power = 1;
	nb = n;
	if (n < 0)
	{
		nb = nb * -1;
		sign = 1;
	}
	while (nb / power >= 10)
	{
		power *= 10;
		i++;
	}
	return (i + sign);
}

static	void	ft_putnbr_str(int n, char *str, int len_str)
{
	long	nb;
	int		sign;
	int		i;

	nb = n;
	sign = 0;
	if (nb < 0)
	{
		str[0] = '-';
		nb = -1 * nb;
		sign++;
	}
	i = len_str - 1;
	while (i >= sign)
	{
		str[i] = (nb % 10) + '0';
		nb = nb / 10;
		i--;
	}
	str[len_str] = '\0';
}

char	*ft_itoa(int n)
{
	char	*str;
	int		len_str;

	len_str = ft_give_len(n);
	str = malloc((len_str + 1) * sizeof(char));
	if (!str)
		return (str);
	ft_putnbr_str(n, str, len_str);
	return (str);
}
/*
#include <stdio.h>
int main(void)
{
	char	*str;
	int	n1 = -2147483648;
	int	n2 = 2147483647;
	int	n3 = 2147483800;
	int	n4 = 0;
	int	n5 = -2456;

	str = ft_itoa(n1);
	printf("%s\n", str);
	free(str);
	str = ft_itoa(n2);
	printf("%s\n", str);
	free(str);
	str = ft_itoa(n3);
	printf("%s\n", str);
	free(str);
	str = ft_itoa(n4);
	printf("%s\n", str);
	free(str);
	str = ft_itoa(n5);
	printf("%s\n", str);
	free(str);
	return (0);
}
*/