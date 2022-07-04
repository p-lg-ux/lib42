/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pgros <pgros@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/02 16:34:19 by pgros             #+#    #+#             */
/*   Updated: 2022/06/08 12:29:39 by pgros            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

static	int	ft_give_nbrlen_base(unsigned long n, int is_signed,
		unsigned long len_base)
{
	int				i;
	unsigned long	power;
	int				sign;
	long			nb;

	sign = 0;
	i = 1;
	power = 1;
	nb = n;
	if (is_signed && nb < 0)
	{
		nb = nb * -1;
		sign = 1;
		n = nb;
	}
	while (n / power >= len_base)
	{
		power *= len_base;
		i++;
	}
	return (i + sign);
}

static	int	ft_putsign_str(char *str, unsigned long *n, long nb,
		int is_signed)
{
	int	sign;

	sign = 0;
	if (is_signed && nb < 0)
	{
		str[0] = '-';
		nb = -1 * nb;
		sign = 1;
		*n = nb;
	}
	return (sign);
}

static	char	*ft_putnbr_base_str(unsigned long n, int len_str, char *base,
		int is_signed)
{
	long	nb;
	int		sign;
	int		i;
	char	*str;
	int		len_base;

	nb = n;
	sign = 0;
	len_base = ft_strlen(base);
	str = malloc((len_str + 1) * sizeof(char));
	if (!str)
		return (str);
	sign = ft_putsign_str(str, &n, nb, is_signed);
	i = len_str - 1;
	while (i >= sign)
	{
		str[i] = base[n % len_base];
		n = n / len_base;
		i--;
	}
	str[len_str] = '\0';
	return (str);
}

char	*ft_itoa_base(unsigned long n, char *base, int is_signed)
{
	char	*str;
	int		len_str;

	len_str = ft_give_nbrlen_base(n, is_signed, ft_strlen(base));
	str = ft_putnbr_base_str(n, len_str, base, is_signed);
	return (str);
}
/*
#include <stdio.h>

int main(void)
{
	int i = 65;
	char *str;

	str = ft_itoa_base(i, DECIMAL, 1);
	printf("|%s|\n", str);
	free(str);
	str = ft_itoa_base(-i, DECIMAL, 1);
	printf("|%s|\n", str);
	free(str);
	str = ft_itoa_base(i, DECIMAL, 0);
	printf("|%s|\n", str);
	free(str);
	str = ft_itoa_base(-i, DECIMAL, 0);
	printf("|%s|\n", str);
	free(str);
	return (0);
}
*/