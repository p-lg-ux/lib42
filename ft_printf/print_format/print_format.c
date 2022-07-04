/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_format.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pgros <pgros@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/01 15:37:34 by pgros             #+#    #+#             */
/*   Updated: 2022/06/08 13:40:37 by pgros            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

/*Prints value with its precision*/
void	print_value(char *value_str, t_format *format)
{
	int	padded;
	int	len_value_str;

	if (value_str[0] == '\0' && format->specifier == C_CHAR)
	{
		ft_putchar_fd(value_str[0], 1);
		format->len_to_print++;
		return ;
	}
	padded = 0;
	len_value_str = ft_strlen(value_str);
	while (len_value_str + padded < format->precision)
	{
		ft_putchar_fd('0', 1);
		padded++;
	}
	ft_putstr_fd(value_str, 1);
	format->len_to_print += len_value_str + padded;
}

/*Prints +, ' ', # and - flags if necessary*/
void	print_flags(t_format *format)
{
	if (format->flags & SPACE)
	{
		ft_putchar_fd(' ', 1);
		format->len_to_print++;
	}
	if (format->flags & PLUS)
	{
		ft_putchar_fd('+', 1);
		format->len_to_print++;
	}
	if (format->flags & MINUS)
	{
		ft_putchar_fd('-', 1);
		format->len_to_print++;
	}
	if (format->flags & SHARP)
	{
		if (format->specifier == X_UP_INT)
			ft_putstr_fd("0X", 1);
		else
			ft_putstr_fd("0x", 1);
		format->len_to_print += 2;
	}
}

/*Prints zeros or spaces padding if necessary*/
void	print_padding(int len_value, t_format *format)
{
	char	pad_char;
	int		len_flags;
	int		padded;

	len_flags = 0;
	if (format->flags & SHARP)
		len_flags += 2;
	if ((format->flags & (SPACE + PLUS + MINUS)))
		len_flags += 1;
	if (len_value + len_flags < format->field_width)
	{
		pad_char = ' ';
		if (format->flags & ZERO)
			pad_char = '0';
		padded = 0;
		while (padded + len_value + len_flags < format->field_width)
		{
			ft_putchar_fd(pad_char, 1);
			padded++;
		}
		format->len_to_print += padded;
	}
}

static int	strlen_value(char *value_str, t_format *format)
{
	if (format->specifier == C_CHAR && *value_str == '\0')
		return (1);
	else
		return (ft_strlen(value_str));
}

void	print_format(char *value_str, t_format *format)
{
	int	len_value;

	len_value = strlen_value(value_str, format);
	if (format->flags & LEFT_JUSTIFY)
	{
		print_flags(format);
		print_value(value_str, format);
		print_padding(len_value, format);
	}
	else
	{
		if (format->flags & ZERO)
		{
			print_flags(format);
			print_padding(len_value, format);
		}
		else
		{
			print_padding(len_value, format);
			print_flags(format);
		}
		print_value(value_str, format);
	}
	free(value_str);
}
