/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pgros <pgros@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/26 17:35:06 by pgros             #+#    #+#             */
/*   Updated: 2022/06/08 12:29:10 by pgros            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <unistd.h>
# include <stdarg.h>
# include "../libft/libft.h"

# define SPECIFIERS	"cspdiuxX%"
# define FLAGS		" +#-0"
# define DECIMAL	"0123456789"
# define HEXA_LOW	"0123456789abcdef"
# define HEXA_UP	"0123456789ABCDEF"

# if defined (__APPLE__)
#  define PTR_NULL "0x0"
#  define IS_APPLE 1
# elif __linux__
#  define PTR_NULL "(nil)"
#  define IS_APPLE 0
# endif

enum e_specifier{
	C_CHAR,
	S_STRING,
	P_POINTER,
	D_INT,
	I_INT,
	U_INT,
	X_LOW_INT,
	X_UP_INT,
	PERCENT,
	NONE,
};

enum e_flags {
	SPACE			= 1,
	PLUS			= 2,
	SHARP			= 4,
	LEFT_JUSTIFY	= 8,
	ZERO			= 16,
	MINUS			= 32,
};

struct s_format {
	enum e_flags		flags;
	int					field_width;
	int					precision;
	enum e_specifier	specifier;
	int					len_to_print;
};

typedef struct s_format		t_format;
typedef enum e_flags		t_flags;
typedef enum e_specifier	t_specifier;
typedef void				(*t_print_func)(va_list ap, t_format *format);

//print_format/convert_format.c
void		convert_format(va_list ap, t_format *format);
void		modify_field_width(t_format *format, int len_value_str);
//print_format/print_c.c
void		print_c(va_list ap, t_format *format);

//print_format/print_s.c
void		print_s(va_list ap, t_format *format);

//print_format/print_p.c
void		print_p(va_list ap, t_format *format);

//print_format/print_d.c
void		print_d(va_list ap, t_format *format);

//print_format/print_i.c
void		print_i(va_list ap, t_format *format);

//print_format/print_u.c
void		print_u(va_list ap, t_format *format);

//print_format/print_xl.c
void		print_xl(va_list ap, t_format *format);

//print_format/print_xu.c
void		print_xu(va_list ap, t_format *format);

//print_format/print_percent.c
void		print_percent(va_list ap, t_format *format);

//print_format/print_none.c
// void		print_none(va_list ap, t_format *format);

//print_format/ft_itoa_base.c
char		*ft_itoa_base(unsigned long n, char *base, int is_signed);

//print_format/print_format.c
void		print_value(char *value, t_format *format);
void		print_flags(t_format *format);
void		print_padding(int len_value, t_format *format);
void		print_format(char *value, t_format *format);

//check_format.c
void		check_precision_and_fw(t_format *format);
void		check_flags_spec_conflicts(t_format *format);
void		check_flags_overwrites(t_format *format);
void		check_format(t_format *format);

//read_format.c
void		read_specifier(const char *input, int *i, t_format *format);
void		read_precision(const char *input, int *i, t_format *format);
void		read_field_width(const char *input, int *i, t_format *format);
void		read_flags(const char *input, int *i, t_format *format);
t_format	read_format(const char *input, int *i);

//ft_printf.c
int			ft_printf(const char *format, ...);

#endif
