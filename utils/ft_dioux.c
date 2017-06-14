/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dioux.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilarbi <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/19 23:06:00 by ilarbi            #+#    #+#             */
/*   Updated: 2017/05/26 14:16:59 by ilarbi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

/*
 **d && i if int == 0, witie NOTHING
 */
int		ft_diouxX(char c, char **format, t_format **f)
{
	int		result;
	va_list	ap;
	char	*fmt;

	if (!format || !*format || !f || !*f)
		return (-1);
	fmt = *format;
	va_start(ap, fmt);
	result = va_arg(ap, fmt);
	if (*fmt == 'i' || *fmt == 'd' || *fmt == 'u')
		if (result == 0 && (*f)->width->max == 0)
		{
			fmt++;
			ft_memdel(f);
		}
	if (*fmt == 'o')
	{
		ft_convert_base(result, 8);
	}
	va_end(ap);
	return (result);
}
