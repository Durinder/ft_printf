/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   conversion_percentage.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhallama <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/18 16:30:51 by jhallama          #+#    #+#             */
/*   Updated: 2019/12/18 18:30:58 by jhallama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "libft/libft.h"

static void	print(t_fields *fields)
{
	if (fields->min != 0 && fields->precision != 0)
	{
		write(1, "%", 1);
		fields->result++;
	}
}

void		conversion_percentage(t_fields *fields)
{
	if (fields->zero == 1 && fields->minus == 0)
	{
		while (fields->min > 1)
		{
			fields->min--;
			write(1, "0", 1);
			fields->result++;
		}
	}
	print(fields);
	if (fields->minus == 1 && fields->zero == 0)
	{
		while (fields->min-- > 1 && fields->precision-- != 0)
		{
			write(1, " ", 1);
			fields->result++;
		}
	}
}
