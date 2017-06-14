/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert_unsigned.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilarbi <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/20 22:37:53 by ilarbi            #+#    #+#             */
/*   Updated: 2017/05/22 11:56:12 by ilarbi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

/*
 ** ouxX
 */

uintmax_t	ft_convert_unsigned(char **format, ...)
{
	va_list		ap;
	uintmax_t	result;

	if (!format || !*format)
		return (-1);
	va_start(ap, format);
	result = va_arg(ap, uintmax_t);
	va_end(ap);
	(*format)++;
	return (result);
}
