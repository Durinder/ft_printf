/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   choose_type.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhallama <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/03 14:44:52 by jhallama          #+#    #+#             */
/*   Updated: 2020/01/03 15:35:46 by jhallama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "libft/libft.h"

static char	*choose_more2(char *s, t_fields *fields)
{
	t_length_type	length;

	if (fields->l != 1 && fields->ll != 1 && fields->h != 1 && fields->hh != 1)
	{
		length.int_n = va_arg(fields->ap, int);
		if (length.int_n == 0 && fields->plus == 0)
			s = ft_strnew(0);
		else
			s = ft_itoa(length.int_n);
	}
	return (s);
}

static char	*choose_more(char *s, t_fields *fields)
{
	t_length_type	length;

	if (fields->h == 1)
	{
		length.short_n = va_arg(fields->ap, int);
		s = ft_itoa(length.short_n);
	}
	else if (fields->hh == 1)
	{
		length.signed_char_n = va_arg(fields->ap, int);
		s = ft_itoa(length.signed_char_n);
	}
	s = choose_more2(s, fields);
	return (s);
}

char		*choose_type(t_fields *fields)
{
	char			*s;
	t_length_type	length;

	s = NULL;
	if (fields->l == 1)
	{
		length.long_n = va_arg(fields->ap, long);
		s = ft_itoa_ll(length.long_n);
	}
	else if (fields->ll == 1)
	{
		length.long_long_n = va_arg(fields->ap, long long);
		s = ft_itoa_ll(length.long_long_n);
	}
	s = choose_more(s, fields);
	return (s);
}