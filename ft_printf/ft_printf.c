/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pgros <pgros@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/26 18:00:29 by pgros             #+#    #+#             */
/*   Updated: 2022/06/08 12:28:54 by pgros            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdio.h>

static int	read_check_print_format(const char *input, int *i, va_list ap)
{
	t_format	format;

	format = read_format(input, i);
	check_format(&format);
	convert_format(ap, &format);
	return (format.len_to_print);
}

int	ft_printf(const char *input, ...)
{
	int			printed;
	int			i;
	va_list		ap;

	if (input == NULL)
		return (0);
	va_start(ap, input);
	printed = 0;
	i = 0;
	while (input[i] != '\0')
	{
		if (input[i] == '%')
		{
			i++;
			printed += read_check_print_format(input, &i, ap);
		}
		else
		{
			ft_putchar_fd(input[i], 1);
			printed++;
			i++;
		}	
	}
	va_end(ap);
	return (printed);
}
/*
int main(int ac, char **av)
{
	// char *a = NULL;
	int b = -65;
	
	(void) ac;
	// (void) av;
	printf("%d\n", (printf(av[1], b)));
	printf("%d\n", (ft_printf(av[1], b)));
	printf("%d\n", (printf(av[1], -b)));
	printf("%d\n", (ft_printf(av[1], -b)));
	//printf("%d\n", (printf("|%10.5d|", b)));
	
	// printf("%c\n", 0);
	// printf("%s\n", NULL);
	// printf("lol %s\n", "");
	//printf("%.6s\n", NULL);
	//printf("size of struct  = %ld\n", sizeof(t_format));
	//printf("size = %ld\n", sizeof(t_specifier));

	return (0);
}
*/