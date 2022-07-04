/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_format.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pgros <pgros@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/30 16:05:15 by pgros             #+#    #+#             */
/*   Updated: 2022/06/08 12:31:45 by pgros            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	read_specifier(const char *input, int *i, t_format *format)
{
	const int	specifiers_map[] = {
	['c'] = C_CHAR,
	['s'] = S_STRING,
	['p'] = P_POINTER,
	['d'] = D_INT,
	['i'] = I_INT,
	['u'] = U_INT,
	['x'] = X_LOW_INT,
	['X'] = X_UP_INT,
	['%'] = PERCENT,
	};

	if (ft_strchr(SPECIFIERS, input[*i]))
	{
		format->specifier = specifiers_map[(int)input[*i]];
		*i += 1;
	}
}

void	read_precision(const char *input, int *i, t_format *format)
{
	if (input[*i] == '.')
	{
		*i += 1;
		format->precision = 0;
		while (ft_strchr(DECIMAL, input[*i]))
		{
			format->precision = format->precision * 10 + (input[*i] - '0');
			*i += 1;
		}
	}
}

void	read_field_width(const char *input, int *i, t_format *format)
{
	while (ft_strchr(DECIMAL, input[*i]))
	{
		format->field_width = format->field_width * 10 + (input[*i] - '0');
		*i += 1;
	}
}

void	read_flags(const char *input, int *i, t_format *format)
{
	const t_flags	flags_map[] = {
	[' '] = SPACE,
	['+'] = PLUS,
	['#'] = SHARP,
	['-'] = LEFT_JUSTIFY,
	['0'] = ZERO,
	};

	while (ft_strchr(FLAGS, input[*i]))
	{
		format->flags |= flags_map[(int)input[*i]];
		*i += 1;
	}
}

t_format	read_format(const char *input, int *i)
{
	t_format	format;
	int			j;

	format.flags = 0;
	format.field_width = 0;
	format.precision = -1;
	format.len_to_print = 0;
	format.specifier = NONE;
	j = *i;
	read_flags(input, &j, &format);
	read_field_width(input, &j, &format);
	read_precision(input, &j, &format);
	read_specifier(input, &j, &format);
	if (format.specifier == NONE)
		format.specifier = PERCENT;
	else
		*i = j;
	return (format);
}
