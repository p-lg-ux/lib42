/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_format.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pgros <pgros@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/30 16:38:48 by pgros             #+#    #+#             */
/*   Updated: 2022/06/08 12:31:35 by pgros            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	check_precision_and_fw(t_format *format)
{
	if (format->specifier == PERCENT)
	{
		format->precision = -1;
		format->field_width = 0;
	}
	if (format->specifier == C_CHAR)
		format->precision = -1;
}

void	check_flags_spec_conflicts(t_format *format)
{
	if (format->specifier == C_CHAR || format->specifier == S_STRING)
		format->flags &= LEFT_JUSTIFY;
	if (format->specifier == D_INT || format->specifier == I_INT
		|| format->specifier == P_POINTER)
		format->flags &= ~SHARP;
	if (format->specifier == U_INT)
		format->flags &= (LEFT_JUSTIFY | ZERO);
	if (format->specifier == X_LOW_INT || format->specifier == X_UP_INT)
		format->flags &= (LEFT_JUSTIFY | ZERO | SHARP);
	if (format->specifier == PERCENT)
		format->flags &= 0;
}

void	check_flags_overwrites(t_format *format)
{
	if ((format->flags & PLUS) && (format->flags & SPACE))
		format->flags &= ~SPACE;
	if ((format->flags & ZERO) && (format->flags & LEFT_JUSTIFY))
		format->flags &= ~ZERO;
	if ((format->flags & ZERO) && format->precision >= 0)
		format->flags &= ~ZERO;
}

void	check_format(t_format *format)
{
	check_flags_spec_conflicts(format);
	check_precision_and_fw(format);
	check_flags_overwrites(format);
}
