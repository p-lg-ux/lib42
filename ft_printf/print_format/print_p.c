/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_p.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pgros <pgros@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/02 16:09:21 by pgros             #+#    #+#             */
/*   Updated: 2022/06/08 12:30:15 by pgros            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

void	print_p(va_list ap, t_format *format)
{
	unsigned long	arg;
	char			*value_str;

	arg = va_arg(ap, unsigned long);
	if (arg == 0)
	{
		value_str = malloc((ft_strlen(PTR_NULL) + 1) * sizeof(char));
		if (value_str == NULL)
			return ;
		ft_strlcpy(value_str, PTR_NULL, (ft_strlen(PTR_NULL) + 1));
		format->flags &= ~(ZERO | SPACE | PLUS);
		format->precision = -1;
	}
	else
	{
		value_str = ft_itoa_base(arg, HEXA_LOW, 0);
		if (value_str == NULL)
			return ;
		format->flags |= SHARP;
		modify_field_width(format, ft_strlen(value_str));
	}
	print_format(value_str, format);
}
