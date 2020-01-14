/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_float_round.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhallama <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/13 16:24:29 by jhallama          #+#    #+#             */
/*   Updated: 2020/01/13 19:36:31 by jhallama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	*rounding(char *s, const char *src, long long precision)
{
	size_t	carry;
	size_t	i;

	carry = 0;
	i = 0;
	if (src[precision] >= '5')
	{
		carry++;
		i = precision;
		while (src[--i] >= '9' && i >= 0)
			carry++;
	}
	while (precision--)
	{
		if (carry)
		{
			s[precision] = src[precision] + 1;
			if (s[precision] == 58)
				s[precision] = '0';
			carry--;
		}
		else
			s[precision] = src[precision];
	}
	return (s);
}

static char	*decimal_assignment(const char *src, long long precision,
		long long len)
{
	char	*s;
	size_t	i;

	if (!(s = ft_strnew(precision)))
		return (NULL);
	i = 0;
	if (len <= precision)
	{
		while (len-- && precision--)
		{
			s[i] = src[i];
			i++;
		}
		while (precision--)
			s[i++] = '0';
	}
	else
	{
		s = rounding(s, src, precision);
	}
	return (s);
}

static char	*decimal_overflow_assignment(char *s, long long len,
		long long carry)
{
	if (len == -1)
	{
		len = ft_strlen(s);
		if (!(s = ft_strnew(ft_strlen(s))))
			return (NULL);
		s[0] = '1';
		s[len] = '.';
		while (len-- > 1)
			s[len] = '0';
	}
	else
	{
		len = ft_strlen(s) - 2;
		while (carry--)
		{
			s[len--] += 1;
			if (s[len + 1] == 58)
				s[len + 1] = '0';
		}
	}
	return (s);
}

static char	*check_decimal_overflow(char *s, const char *src, long long len,
		long long precision)
{
	size_t	carry;

	if (len <= precision)
		return (s);
	if (src[precision--] >= '5')
	{
		while (src[precision] == '9' && precision >= 0)
			precision--;
		if (precision == -1)
		{
			len = ft_strlen(s) - 2;
			carry = 1;
			while (len >= 0 && s[len] == '9')
			{
				len--;
				carry++;
			}
			s = decimal_overflow_assignment(s, len, carry);
		}
	}
	return (s);
}

char		*ft_float_round(const char *src, long long precision)
{
	char		*s;
	long long	len;

	len = 0;
	if (*src)
	{
		if (precision <= 0)
			precision = 6;
		while (src[len] != '.' && src[len] != '\0')
			len++;
		if (!(s = ft_strnew(len)))
			return (NULL);
		s[len] = '.';
		while (len--)
			s[len] = src[len];
		while (*src != '.' && *src != '\0')
			src++;
		if (*src == '.')
			src++;
		s = check_decimal_overflow(s, src, (long long)ft_strlen(src),
				precision);
		s = ft_strjoin(s, decimal_assignment(src, precision, ft_strlen(src)));
		return (s);
	}
	return (NULL);
}
