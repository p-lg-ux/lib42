/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_s.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pgros <pgros@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/02 13:10:26 by pgros             #+#    #+#             */
/*   Updated: 2022/06/08 14:21:04 by pgros            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

static char	*generate_value_str(char *src, int precision, int end_position)
{
	char	*value_str;
	int		len_src;

	len_src = ft_strlen(src);
	value_str = malloc((len_src + 1) * sizeof(char));
	if (value_str == NULL)
		return (NULL);
	ft_strlcpy(value_str, src, len_src + 1);
	if (precision > -1 && precision < len_src)
		value_str[end_position] = '\0';
	return (value_str);
}

void	print_s(va_list ap, t_format *format)
{
	char	*arg;
	char	*value_str;

	arg = (char *)va_arg(ap, char *);
	if (arg == NULL)
	{
		value_str = generate_value_str("(null)", format->precision, 0);
		if (value_str == NULL)
			return ;
	}
	else
	{
		value_str = generate_value_str(arg, format->precision,
				format->precision);
		if (value_str == NULL)
			return ;
	}
	format->precision = -1;
	print_format(value_str, format);
}
