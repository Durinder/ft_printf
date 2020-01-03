/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   conversion_d.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhallama <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/19 15:59:08 by jhallama          #+#    #+#             */
/*   Updated: 2020/01/03 16:21:06 by jhallama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "libft/libft.h"

static void	precision_and_print(t_fields *fields, char *s)
{
	int s_len;

	s_len = ft_strlen(s);
	if (s[0] == '-')
	{
		s++;
		s_len--;
	}
	while (fields->precision > s_len)
	{
		fields->precision--;
		fields->min--;
		write(1, "0", 1);
		fields->result++;
	}
	while (s_len--)
	{
		fields->min--;
		write(1, s++, 1);
		fields->result++;
	}
}

static void	sign_check_and_extra_spaces(t_fields *fields, char *s)
{
	int	s_len;

	s_len = ft_strlen(s);
	if (s[0] == '-' && fields->min >= s_len &&
			fields->plus == 0 && fields->zero == 0)
	{
		write(1, "-", 1);
		fields->min--;
		fields->result++;
	}
	else if (fields->plus == 1 && fields->min >= fields->precision &&
			fields->precision != -1)
	{
		write(1, "+", 1);
		fields->min--;
		fields->result++;
	}
	if (fields->precision != -1 && fields->minus == 0)
		while (fields->min > fields->precision)
		{
			write(1, " ", 1);
			fields->min--;
			fields->result++;
		}
}

static void	left_padding(t_fields *fields, char *s)
{
	if (fields->space == 1 && fields->plus == 0 && s[0] != '-')
	{
		write(1, " ", 1);
		fields->min--;
		fields->result++;
	}
	while (fields->zero == 0 && fields->minus == 0 &&
			fields->min > fields->precision + 1 &&
			fields->min > (int)ft_strlen(s))
	{
		write(1, " ", 1);
		fields->min--;
		fields->result++;
	}
	if (fields->zero == 1 && fields->precision == -1 && fields->minus == 0)
		while (fields->min > (int)ft_strlen(s) ||
				(s[0] == '-' && fields->min >= (int)ft_strlen(s)))
		{
			fields->min--;
			write(1, "0", 1);
			fields->result++;
		}
}

void		conversion_d(t_fields *fields)
{
	char	*s;

	if (fields->prec_astr == 1)
		fields->precision = va_arg(fields->ap, int);
	s = choose_type(fields);
	if ((fields->plus == 1 && (fields->min < fields->precision ||
				fields->precision == -1)) || (s[0] == '-' && fields->min <
				(int)ft_strlen(s)) || (s[0] == '-' && fields->zero == 1))
	{
		s[0] == '-' ? write(1, "-", 1) : write(1, "+", 1);
		fields->min--;
		fields->result++;
	}
	left_padding(fields, s);
	sign_check_and_extra_spaces(fields, s);
	precision_and_print(fields, s);
	if (fields->minus == 1)
		while (fields->min-- > 0)
		{
			write(1, " ", 1);
			fields->result++;
		}
	ft_strdel(&s);
}
