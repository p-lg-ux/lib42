/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_c.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pgros <pgros@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/01 14:41:31 by pgros             #+#    #+#             */
/*   Updated: 2022/06/08 12:29:44 by pgros            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

void	print_c(va_list ap, t_format *format)
{
	int		c;
	char	*value;

	c = (char)va_arg(ap, int);
	value = malloc(2 * sizeof(char));
	value[0] = c;
	value[1] = '\0';
	print_format(value, format);
}
