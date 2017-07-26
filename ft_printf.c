/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilarbi <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/09 21:55:07 by ilarbi            #+#    #+#             */
/*   Updated: 2017/07/26 21:51:39 by ilarbi           ###   ########.fr       */
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
	ft_printf("%#o\n", 42);
	ft_printf("%#o\n", 0);
	ft_printf("%#o\n", INT_MAX);
	ft_printf("%#O\n", 1);
	ft_printf("%#x\n", 42);
	ft_printf("%#x\n", 0);
	ft_printf("%#x\n", INT_MAX);
	ft_printf("%#X\n", 42);
	ft_printf("%#X\n", 0);
	ft_printf("%#X\n", INT_MAX);
	ft_printf("%#c", 0);
	//ft_printf("%hho, %hho\n", 0, UCHAR_MAX + 42);
	//ft_printf("%hhx, %hhx\n", 0, UCHAR_MAX + 42);
	//ft_printf("segf %hhX, %hhX\n", 0, UCHAR_MAX + 42);

//	printf("je retourne %d\n", ft_printf("%#c\n", 0));
//	printf("%#c", 0);
	//ft_putnbr(printf("{%10R}"));
	//ft_printf("%S", L"β");
	//ft_putnbr(ft_printf("%05c", 42));
	//	ft_putnbr(printf("%05c", 42));
	//ft_putnbr(ft_printf("% c", 0));
	//	ft_printf("%S%S%S%S%S%S%S%S%S%S%S%S%S%S%S%S%S%S%S%S%S%S%S%S%S",
	//			    L"Α α", L"Β β", L"Γ γ", L"Δ δ", L"Ε ε", L"Ζ ζ", L"Η η", L"Θ θ", L"Ι ι", L"Κ κ", L"Λ λ", L"Μ μ",
	//				    L"Ν ν", L"Ξ ξ", L"Ο ο", L"Π π", L"Ρ ρ", L"Σ σ", L"Τ τ", L"Υ υ", L"Φ φ", L"Χ χ", L"Ψ ψ", L"Ω ω", L"");
//  while (1);
	return (0);
}
*/
