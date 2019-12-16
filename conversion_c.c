/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   conversion_c.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhallama <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/16 17:28:59 by jhallama          #+#    #+#             */
/*   Updated: 2019/12/16 17:32:58 by jhallama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.c"

void	conversion_c(const char *format, t_fields fields, size_t result)
{
	char c;

	format++;
	c = va_arg(fields.ap, char);
	write(1, &c, 1);
	result++;
}
