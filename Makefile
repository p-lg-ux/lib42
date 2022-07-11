# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: pgros <pgros@student.42.fr>                +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/05/04 16:14:26 by pgros             #+#    #+#              #
#    Updated: 2022/07/11 15:10:07 by pgros            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = lib42.a

SRC_LIBFT = ft_isalnum.c \
       		ft_isalpha.c \
			ft_isdigit.c \
			ft_isascii.c \
			ft_isprint.c \
			ft_memset.c \
			ft_bzero.c \
			ft_strlen.c \
			ft_memcpy.c \
			ft_memmove.c \
			ft_strlcpy.c \
			ft_strlcat.c \
			ft_toupper.c \
			ft_tolower.c \
			ft_strchr.c \
			ft_strrchr.c \
			ft_strncmp.c \
			ft_memchr.c \
			ft_memcmp.c \
			ft_strnstr.c \
			ft_atoi.c \
			ft_calloc.c \
			ft_strdup.c \
			ft_substr.c \
			ft_strjoin.c \
			ft_strtrim.c \
			ft_split.c \
			ft_itoa.c \
			ft_strmapi.c \
			ft_striteri.c \
			ft_putchar_fd.c \
			ft_putstr_fd.c \
			ft_putendl_fd.c \
			ft_putnbr_fd.c \
			ft_lstnew_bonus.c \
			ft_lstadd_front_bonus.c \
			ft_lstsize_bonus.c \
			ft_lstlast_bonus.c \
			ft_lstadd_back_bonus.c \
			ft_lstdelone_bonus.c \
			ft_lstclear_bonus.c \
			ft_lstiter_bonus.c \
			ft_lstmap_bonus.c \
			ft_llstnew.c \
			ft_llstadd_back.c \
			ft_llstadd_front.c \
			ft_llstdelone.c \
			ft_llstlast.c \
			ft_llstclear.c \
			ft_llstsize.c

SRC_FTPRINTF = ft_printf.c\
		read_format.c\
		check_format.c\
		print_format/convert_format.c\
		print_format/print_format.c\
		print_format/ft_itoa_base.c\
		print_format/print_c.c\
		print_format/print_s.c\
		print_format/print_p.c\
		print_format/print_d.c\
		print_format/print_i.c\
		print_format/print_u.c\
		print_format/print_xl.c\
		print_format/print_xu.c\
		print_format/print_percent.c

SRC_GNL = get_next_line_bonus.c\
			get_next_line_utils_bonus.c


PREFIX_LIBFT = ./libft/

PREFIX_FTPRINTF = ./ft_printf/

PREFIX_GNL = ./get_next_line/

SRC_LIBFT_PREFIXED = $(addprefix $(PREFIX_LIBFT), $(SRC_LIBFT))

SRC_FTPRINTF_PREFIXED = $(addprefix $(PREFIX_FTPRINTF), $(SRC_FTPRINTF))

SRC_GNL_PREFIXED = $(addprefix $(PREFIX_GNL), $(SRC_GNL))

OBJS_LIBFT = $(SRC_LIBFT_PREFIXED:.c=.o)

OBJS_FTPRINTF = $(SRC_FTPRINTF_PREFIXED:.c=.o)

OBJS_GNL = $(SRC_GNL_PREFIXED:.c=.o)

OBJS = $(OBJS_LIBFT) $(OBJS_FTPRINTF) $(OBJS_GNL)

COMPILER_COMMAND = gcc

AR = ar rcs

RM = rm -f

CFLAGS = -Wall -Werror -Wextra

.c.o = $(COMPILER_COMMAND) $(CFLAGS) -c $< -o $(<:.c=.o)

$(NAME): $(OBJS)
	$(AR) $(NAME) $(OBJS)

all:	$(NAME)

clean:
	$(RM) $(OBJS)

fclean: clean
	$(RM) $(NAME)

re:	fclean all

print: $(OBJS_GNL)
	echo $(OBJS_GNL)
.PHONY : all clean fclean re