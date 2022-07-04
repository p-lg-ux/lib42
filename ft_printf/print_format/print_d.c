/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_d.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pgros <pgros@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/02 19:23:48 by pgros             #+#    #+#             */
/*   Updated: 2022/06/14 14:31:24 by pgros            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

void	print_d(va_list ap, t_format *format)
{
	int		arg;
	char	*value_str;
	char	*tmp;

	arg = va_arg(ap, int);
	value_str = ft_itoa_base(arg, DECIMAL, 1);
	if (value_str == NULL)
		return ;
	if (arg < 0)
	{
		format->flags &= ~(SPACE | PLUS);
		format->flags |= MINUS;
		tmp = ft_substr(value_str, 1, ft_strlen(value_str) - 1);
		free(value_str);
		if (tmp == NULL)
			return ;
		value_str = tmp;
	}
	if (arg == 0 && format->precision == 0)
		value_str[0] = '\0';
	modify_field_width(format, ft_strlen(value_str));
	print_format(value_str, format);
}
