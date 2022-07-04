/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_u.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pgros <pgros@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/03 15:20:49 by pgros             #+#    #+#             */
/*   Updated: 2022/06/14 14:34:27 by pgros            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

void	print_u(va_list ap, t_format *format)
{
	unsigned int	arg;
	char			*value_str;

	arg = va_arg(ap, unsigned int);
	value_str = ft_itoa_base(arg, DECIMAL, 0);
	if (value_str == NULL)
		return ;
	if (arg == 0 && format->precision == 0)
		value_str[0] = '\0';
	modify_field_width(format, ft_strlen(value_str));
	print_format(value_str, format);
}
