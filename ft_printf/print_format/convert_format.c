/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   convert_format.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pgros <pgros@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/01 13:44:09 by pgros             #+#    #+#             */
/*   Updated: 2022/06/08 12:29:18 by pgros            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

void	convert_format(va_list ap, t_format *format)
{
	const t_print_func	print_funcs_map[] = {
	[C_CHAR] = &print_c,
	[S_STRING] = &print_s,
	[P_POINTER] = &print_p,
	[D_INT] = &print_d,
	[I_INT] = &print_i,
	[U_INT] = &print_u,
	[X_LOW_INT] = &print_xl,
	[X_UP_INT] = &print_xu,
	[PERCENT] = &print_percent,
	};

	print_funcs_map[format->specifier](ap, format);
}

void	modify_field_width(t_format *format, int len_value_str)
{
	int		precision_padding;

	precision_padding = format->precision - len_value_str;
	if (format->field_width > 0 && format->precision > -1
		&& precision_padding > 0)
		format->field_width -= precision_padding;
}
