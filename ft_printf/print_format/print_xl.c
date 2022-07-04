/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_xl.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pgros <pgros@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/03 16:15:28 by pgros             #+#    #+#             */
/*   Updated: 2022/06/14 14:35:28 by pgros            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

void	print_xl(va_list ap, t_format *format)
{
	unsigned int	arg;
	char			*value_str;

	arg = va_arg(ap, unsigned int);
	value_str = ft_itoa_base(arg, HEXA_LOW, 0);
	if (value_str == NULL)
		return ;
	if (arg == 0)
	{
		format->flags &= ~SHARP;
		if (format->precision == 0)
			value_str[0] = '\0';
	}
	modify_field_width(format, ft_strlen(value_str));
	print_format(value_str, format);
}
