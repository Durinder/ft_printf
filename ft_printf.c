/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhallama <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/13 16:05:49 by jhallama          #+#    #+#             */
/*   Updated: 2019/12/16 17:28:10 by jhallama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "libft/libft.h"

static void	choose_conversion(const char *format, t_fields fields, size_t result)
{
	if (*format == 'c')
		conversion_c(format, fields, result);
	if (*format == 's')
		conversion_s(format, fields, result);
	if (*format == 'p')
		conversion_p(format, fields, result);
	if (*format == 'd')
		conversion_d(format, fields, result);
	if (*format == 'i')
		conversion_i(format, fields, result);
	if (*format == 'o')
		conversion_o(format, fields, result);
	if (*format == 'u')
		conversion_u(format, fields, result);
	if (*format == 'x')
		conversion_x(format, fields, result);
	if (*format == 'X')
		conversion_X(format, fields, result);
	if (*format == 'f')
		conversion_f(format, fields, result);
}

static void	magic(const char *format, t_fields fields, size_t result)
{
	while (*format)
	{
		if (*format == '%')
		{
			if (*(format + 1) == '%')
			{
				result++;
				format++;
				write(1, "%", 1);
			}
			else
			{
				choose_flags(format, fields);
				choose_width_and_precision(format, fields);
				choose_length(format, fields);
				choose_conversion(format, fields, result);
			}
		}
		else
		{
			result++;
			write(1, format, 1);
		}
		format++;
	}
}

int			ft_printf(const char *format, ...)
{
	size_t		result;
	t_fields	fields;

	result = 0;
	va_start(fields.ap, format);
	magic(format, fields, result);
	va_end(fields.ap);
	return (result);
}
