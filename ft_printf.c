/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilarbi <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/09 21:55:07 by ilarbi            #+#    #+#             */
/*   Updated: 2017/07/19 21:50:44 by ilarbi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
 * *a enlever pas inc inutiles
 */ 
#include <stdio.h>
#include "ft_printf.h"
#include "locale.h"

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
			if (ft_convert(&format, &written, ap))
				format++;
		}
	}
	va_end(ap);
	return (written);
}
/*
int		main()
{
	setlocale(LC_ALL, "");
	ft_printf("\n");
	ft_printf("%%\n");
	ft_printf("%d\n", 42);
	ft_printf("%d%d\n", 42, 41);
	ft_printf("%d%d%d\n", 42, 43, 44);
	ft_printf("%ld\n", 2147483647);
	ft_printf("%lld\n", 9223372036854775807);
	ft_printf("%x\n", 505);
	ft_printf("%X\n", 505);
	ft_printf("%p\n", &ft_printf);
	ft_printf("%20.15d\n", 54321);
	ft_printf("%-10d\n", 3);
	ft_printf("% d\n", 3);
	ft_printf("%+d\n", 3);
	ft_printf("%010d\n", 1);
	ft_printf("%hhd\n", 0);
	ft_printf("%jd\n", 9223372036854775807);
	ft_printf("%zd\n", 4294967295);
	ft_printf("%\n");
	ft_printf("%U\n", 4294967295);
	ft_printf("%u\n", 4294967295);
	ft_printf("%o\n", 40);
	ft_printf("%%#08x\n", 42);
	ft_printf("%x\n", 1000);
	ft_printf("%#X\n", 1000);;
	ft_printf("%s\n", NULL);
	ft_printf("%S\n", L"ݗݜशব");ft_printf("%s%s\n", "test", "test");
	  ft_printf("%s%s%s\n", "test", "test", "test");
	    ft_printf("%C\n", 15000);
		  while (1);
	//ft_printf("%S", L"β");
	//ft_putnbr(ft_printf("%05c", 42));
	//	ft_putnbr(printf("%05c", 42));
	//ft_putnbr(ft_printf("% c", 0));
	//	ft_printf("%S%S%S%S%S%S%S%S%S%S%S%S%S%S%S%S%S%S%S%S%S%S%S%S%S",
	//			    L"Α α", L"Β β", L"Γ γ", L"Δ δ", L"Ε ε", L"Ζ ζ", L"Η η", L"Θ θ", L"Ι ι", L"Κ κ", L"Λ λ", L"Μ μ",
	//				    L"Ν ν", L"Ξ ξ", L"Ο ο", L"Π π", L"Ρ ρ", L"Σ σ", L"Τ τ", L"Υ υ", L"Φ φ", L"Χ χ", L"Ψ ψ", L"Ω ω", L"");
	return (0);
}
*/
