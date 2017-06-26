/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilarbi <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/09 21:55:07 by ilarbi            #+#    #+#             */
/*   Updated: 2017/06/26 22:30:40 by ilarbi           ###   ########.fr       */
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
	va_list ap;

	if (!format)
		return (-1);
	written = 0;
	va_start(ap, format);
	while (*format)
	{
		if (*format != '%')
		{
			ft_putchar(*format++);
			written++;
		}
		else if (*format == '%' && format++)
		{	
			ft_convert(&format, &written, ap);
			format++;
		}
	}
	va_end(ap);
	return (written);
}

int		main()
{
//	char *str = "abc";/
	//ft_printf("%+u", UINT_MAX);
	ft_printf("@moulitest: %5.o %5.0o", 0, 0);
	//ft_printf("%.10s est une phrase\n", "");
//	printf("%10s est une phrase\n", "");
	//ft_putnbr(ft_printf("%010d", -145));
	//printf("%010d", -145);
	return (0);
}

