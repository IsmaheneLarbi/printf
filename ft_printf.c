/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilarbi <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/09 21:55:07 by ilarbi            #+#    #+#             */
/*   Updated: 2017/05/13 22:58:54 by ilarbi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
 * *a enlever pas inc inutiles
*/ 
#include <stdio.h>
#include "ft_printf.h"

int		ft_printf(const char *format, ...)
{
	int		written;

	written = 0;
	while (format && *format)
	{
		if (*format != '%')
		{
			ft_putchar(*format++);
			written++;
		}
		else if (*format == '%')
		{	
			printf("conversion ...\n");
			ft_convert(&format, &written);
		}
	}
	return (written);
}
