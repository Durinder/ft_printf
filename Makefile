# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jhallama <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/10/15 16:10:31 by jhallama          #+#    #+#              #
#    Updated: 2020/01/17 20:13:03 by jhallama         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a

LIBFTSRC = ft_memset.c ft_bzero.c ft_memcpy.c ft_memccpy.c ft_memmove.c ft_memchr.c ft_memcmp.c ft_strlen.c ft_strdup.c ft_strcpy.c ft_strncpy.c ft_strcat.c ft_strncat.c ft_strlcat.c ft_strchr.c ft_strrchr.c ft_strstr.c ft_strnstr.c ft_strcmp.c ft_strncmp.c ft_atoi.c ft_isalpha.c ft_isdigit.c ft_isalnum.c ft_isprint.c ft_isascii.c ft_toupper.c ft_tolower.c ft_memalloc.c ft_memdel.c ft_strnew.c ft_strdel.c ft_strclr.c ft_striter.c ft_striteri.c ft_strmap.c ft_strmapi.c ft_strequ.c ft_strnequ.c ft_strsub.c ft_strjoin.c ft_strtrim.c ft_strsplit.c ft_itoa.c ft_putchar.c ft_putstr.c ft_putendl.c ft_putnbr.c ft_putchar_fd.c ft_putstr_fd.c ft_putendl_fd.c ft_putnbr_fd.c ft_lstnew.c ft_lstdelone.c ft_lstdel.c ft_lstadd.c ft_lstiter.c ft_lstmap.c get_next_line.c ft_itoa_base.c ft_nbrlen.c ft_itoa_ll.c ft_itoa_ull.c ft_itoa_base_ull.c ft_itoa_float.c ft_float_round.c

PRINTFSRC = ft_printf.c format_specification_fields.c conversion_percentage.c conversion_c.c conversion_s.c conversion_p.c conversion_di.c choose_type_di.c conversion_o.c choose_type_o.c conversion_u.c choose_type_u.c conversion_x.c choose_type_x.c conversion_cap_x.c conversion_f.c choose_type_f.c

HEADERS = -I libft.h -I get_next_line.h -I ft_printf.h

OBJ = $(LIBFTSRC:.c=.o) $(PRINTFSRC:.c=.o)

.PHONY: all clean fclean re

all: $(NAME)

$(NAME):
	gcc -Wall -Wextra -Werror -c $(LIBFTSRC:%.c=libft/%.c) $(PRINTFSRC) $(HEADERS)
	ar -rc $(NAME) $(OBJ)
	ranlib $(NAME)

clean:
	/bin/rm -f $(OBJ)

fclean: clean
	/bin/rm -f $(NAME)

re: fclean all
