/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhallama <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/14 12:02:43 by jhallama          #+#    #+#             */
/*   Updated: 2019/12/18 16:17:55 by jhallama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include <stdarg.h>
# include <unistd.h>
# include <stdlib.h>

typedef struct	s_fields {
	va_list	ap;
	size_t	result;

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
const char		*choose_flags(const char *format, t_fields *fields);
const char		*choose_width_and_precision(const char *format, t_fields *fields);
const char		*choose_length(const char *format, t_fields *fields);
void			conversion_percentage(t_fields *fields);
void			conversion_c(t_fields *fields);
void			conversion_s(t_fields *fields);
void			conversion_p(const char *format, t_fields fields, size_t result);
void			conversion_d(const char *format, t_fields fields, size_t result);
void			conversion_i(const char *format, t_fields fields, size_t result);
void			conversion_o(const char *format, t_fields fields, size_t result);
void			conversion_u(const char *format, t_fields fields, size_t result);
void			conversion_x(const char *format, t_fields fields, size_t result);
void			conversion_X(const char *format, t_fields fields, size_t result);
void			conversion_f(const char *format, t_fields fields, size_t result);
#endif
