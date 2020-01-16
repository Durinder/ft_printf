/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_float_round.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhallama <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/13 16:24:29 by jhallama          #+#    #+#             */
/*   Updated: 2020/01/16 16:36:57 by jhallama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char		*rounding(char *s, int precision)
{
	size_t	carry;
	size_t	i;

	carry = 0;
	i = 0;
	if (s[precision] >= '5')
	{
		carry++;
		i = precision;
		while (i >= 0 && s[--i] >= '9')
			carry++;
	}
	while (precision--)
	{
		if (carry)
		{
			s[precision] += 1;
			if (s[precision] == 58)
				s[precision] = '0';
			carry--;
		}
	}
	return (s);
}

static char		*decimal_assignment(char *s, int precision)
{
	char	*tmp;
	size_t	i;

	if ((int)ft_strlen(s) < precision)
	{
		if (!(tmp = ft_strnew(precision)))
			return (NULL);
		i = 0;
		while (s[i])
		{
			tmp[i] = s[i];
			i++;
			precision--;
		}
		while (precision--)
			tmp[i++] = '0';
		ft_strdel(&s);
		return (tmp);
	}
	else
		return (s = rounding(s, precision));
}

static char		*decimal_overflow_assignment(char *s, long long i, size_t carry,
		char *tmp)
{
	if (i == -1 || (i == 0 && s[0] == '-'))
	{
		if (!(tmp = ft_strnew(ft_strlen(s))))
			return (NULL);
		i = 0;
		if (s[0] == '-')
			tmp[i++] = '-';
		tmp[i++] = '1';
		while (carry-- > 1)
			tmp[i++] = '0';
		ft_strdel(&s);
		return (tmp);
	}
	else
	{
		i = ft_strlen(s) - 1;
		while (carry--)
		{
			s[i--] += 1;
			if (s[i + 1] == 58)
				s[i + 1] = '0';
		}
	}
	return (s);
}

static char		*integer_assignment(char *integers, const char *decimals,
		int precision)
{
	char	*tmp;
	size_t	i;
	size_t	carry;

	if ((int)ft_strlen(decimals) <= precision)
		return (integers);
	else if (decimals[precision--] >= '5')
	{
		while (precision >= 0 && decimals[precision] == '9')
			precision--;
		if (precision == -1)
		{
			i = ft_strlen(integers) - 1;
			carry = 1;
			while (i >= 0 && integers[i] == '9')
			{
				i--;
				carry++;
			}
			tmp = NULL;
			integers = decimal_overflow_assignment(integers, i, carry, tmp);
		}
	}
	return (integers);
}

char			*ft_float_round(const char *src, int precision)
{
	char	**array;
	char	*result;
	char	*tmp;
	char	*tmp2;

	if (precision <= 0)
		precision = 6;
	array = ft_strsplit(src, '.');
	array[0] = integer_assignment(array[0], array[1], precision);
	array[1] = decimal_assignment(array[1], precision);
	tmp = (char *)malloc(sizeof(char) * (precision + 1));
	if (tmp == NULL)
		return (NULL);
	tmp2 = ft_strjoin(array[0], ".");
	tmp = ft_memmove(tmp, array[1], precision);
	tmp[precision] = '\0';
	result = ft_strjoin(tmp2, tmp);
	ft_strdel(&tmp);
	ft_strdel(&tmp2);
	ft_strdel(&array[0]);
	ft_strdel(&array[1]);
	ft_strdel(array);
	free(array);
	return (result);
}
