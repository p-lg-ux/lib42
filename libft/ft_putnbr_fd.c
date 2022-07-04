/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pgros <pgros@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/09 16:09:41 by pgros             #+#    #+#             */
/*   Updated: 2022/05/09 16:31:18 by pgros            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putnbr_fd(int n, int fd)
{
	long	nb;

	nb = n;
	if (nb < 0)
	{
		ft_putchar_fd('-', fd);
		nb = nb * -1;
	}
	if (nb < 10)
	{
		ft_putchar_fd((char)('0' + nb), fd);
	}
	else
	{
		ft_putnbr_fd((int)(nb / 10), fd);
		ft_putchar_fd((char)('0' + (nb % 10)), fd);
	}
}
