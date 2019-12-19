/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   conversion_c.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhallama <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/17 12:40:35 by jhallama          #+#    #+#             */
/*   Updated: 2019/12/18 18:25:26 by jhallama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "libft/libft.h"

static void	print(t_fields *fields, int c)
{
	if (fields->min != 0 && fields->precision != 0)
	{
		write(1, &c, 1);
		fields->result++;
	}
}

void		conversion_c(t_fields *fields)
{
	int	c;

	c = va_arg(fields->ap, int);
	if (fields->zero == 1 && fields->minus == 0)
	{
		while (fields->min > 1)
		{
			fields->min--;
			write(1, "0", 1);
			fields->result++;
		}
	}
	print(fields, c);
	if (fields->minus == 1 && fields->zero == 0)
	{
		while (fields->min-- > 1 && fields->precision-- != 0)
		{
			write(1, " ", 1);
			fields->result++;
		}
	}
}
