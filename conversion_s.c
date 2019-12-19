/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   conversion_s.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhallama <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/17 12:40:35 by jhallama          #+#    #+#             */
/*   Updated: 2019/12/19 12:40:10 by jhallama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "libft/libft.h"

static void	print(t_fields *fields, const char *s)
{
	int	s_len;

	s_len = ft_strlen(s);
	while (fields->min != 0 && fields->precision != 0 &&
			s_len-- > 0)
	{
		fields->min--;
		fields->precision--;
		write(1, s++, 1);
		fields->result++;
	}
}

static void	zeroes_and_spaces(t_fields *fields, const char *s, int increment)
{
	if (fields->zero == 1 && fields->minus == 0)
	{
		while (fields->min - (int)ft_strlen(s) > 0)
		{
			fields->min--;
			write(1, "0", 1);
			fields->result++;
		}
	}
	if (fields->precision == -1)
	{
		increment = 1;
		fields->precision++;
	}
	while (fields->minus == 0 && fields->min > (int)ft_strlen(s) -
			fields->precision && fields->min > 0)
	{
		fields->min--;
		write(1, " ", 1);
		fields->result++;
	}
	if (increment == 1)
		fields->precision--;
}

void		conversion_s(t_fields *fields)
{
	const char	*s;
	int			increment;

	if (fields->prec_astr == 1)
		fields->min = va_arg(fields->ap, int);
	s = va_arg(fields->ap, char *);
	if (s == NULL)
	{
		write(1, "(null)", 6);
		fields->result += 6;
	}
	else
	{
		zeroes_and_spaces(fields, s, increment = 0);
		print(fields, s);
		if (fields->minus == 1 && fields->zero == 0)
		{
			while (fields->min-- > 0)
			{
				write(1, " ", 1);
				fields->result++;
			}
		}
	}
}
