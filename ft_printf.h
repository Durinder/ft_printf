/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhallama <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/14 12:02:43 by jhallama          #+#    #+#             */
/*   Updated: 2019/12/16 17:26:44 by jhallama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include <stdarg.h>
# include <unistd.h>
# include <stdlib.h>

typedef struct	s_fields {
	va_list	ap;

	char	hash;
	char	zero;
	char	minus;
	char	plus;
	char	space;

	int		min;
	char	min_astr;

	char	dot;
	int		precision;
	char	prec_astr;

	char	hh;
	char	h;
	char	l;
	char	ll;
}				t_fields;

int				ft_printf(const char *format, ...);
void			choose_flags(const char *format, t_fields fields);
void			choose_width_and_precision(const char *format, t_fields fields);
void			choose_length(const char *format, t_fields fields);
void			conversion_c(const char *format, t_fields fields, size_t result);
void			conversion_s(const char *format, t_fields fields, size_t result);
void			conversion_p(const char *format, t_fields fields, size_t result);
void			conversion_d(const char *format, t_fields fields, size_t result);
void			conversion_i(const char *format, t_fields fields, size_t result);
void			conversion_o(const char *format, t_fields fields, size_t result);
void			conversion_u(const char *format, t_fields fields, size_t result);
void			conversion_x(const char *format, t_fields fields, size_t result);
void			conversion_X(const char *format, t_fields fields, size_t result);
void			conversion_f(const char *format, t_fields fields, size_t result);
#endif
