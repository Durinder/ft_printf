/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhallama <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/19 15:02:08 by jhallama          #+#    #+#             */
/*   Updated: 2019/12/19 15:56:05 by jhallama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_itoa_base(int n, short base)
{
	char	*s;
	short	counter;
	int		tmp;

	if (base == 10)
		return(ft_itoa(n));
	counter = -1;
	tmp = n;
	while (tmp)
	{
		tmp /= base;
		counter++;
	}
	if (!(s = (char *)ft_memalloc(counter + 1)))
		return (NULL);
	while (n)
	{
		tmp = n % base;
		if (tmp < 10)
			s[counter--] = tmp + 48;
		else
			s[counter--] = tmp + 55;
		n /= base;
	}
	return (s);
}
