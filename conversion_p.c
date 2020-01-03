/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   conversion_p.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhallama <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/20 11:57:13 by jhallama          #+#    #+#             */
/*   Updated: 2020/01/03 17:17:30 by jhallama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "libft/libft.h"

static void	print(t_fields *fields, char *s)
{
	int s_len;

	s_len = ft_strlen(s);
	while (fields->min != 0 && s_len-- > 0)
	{
		fields->min--;
		write(1, s++, 1);
		fields->result++;
	}
}

static void	zeroes_and_spaces(t_fields *fields, char *s)
{
	if (fields->zero == 1 && fields->minus == 0)
	{
		while (fields->min - (int)ft_strlen(s) > 2)
		{
			fields->min--;
			write(1, "0", 1);
			fields->result++;
		}
	}
	while (fields->minus == 0 && fields->min - 2 > (int)ft_strlen(s) &&
			fields->min > 2)
	{
		fields->min--;
		write(1, " ", 1);
		fields->result++;
	}
	write(1, "0x", 2);
	fields->result += 2;
}

void		conversion_p(t_fields *fields)
{
	long	n;
	char	*s;

	n = (long)va_arg(fields->ap, void *);
	s = ft_itoa_base(n, 16);
	zeroes_and_spaces(fields, s);
	print(fields, s);
	if (fields->minus == 1 && fields->zero == 0)
	{
		while (fields->min-- > 2)
		{
			write(1, " ", 1);
			fields->result++;
		}
	}
	ft_strdel(&s);
}
