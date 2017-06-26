/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilarbi <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/05 14:48:04 by ilarbi            #+#    #+#             */
/*   Updated: 2017/06/26 21:13:17 by ilarbi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <locale.h>
#include "ft_printf.h"

char	*ft_convert(const char **format, int *written, va_list ap)
{
	t_format	*f;
	int			size;
	char		*number;

	number = NULL;
	size = 0;
	f = ft_parse(format);
	if (*(f->type) == '%')
		number = ft_percent(&f, &size);
	else if (*(f->type) == 'p')
		number = ft_redirect_p(&f, va_arg(ap, void*), &size);
	else if (ft_issigned(*(f->type)))
		number = ft_cast_signed((void *)va_arg(ap, intmax_t), f, &size);
	else if (ft_isunsigned(*(f->type)))
		number = ft_cast_unsigned((void*)va_arg(ap, uintmax_t), f, &size);
	else if (ft_tolower(*(f->type)) == 'c')
		number = ft_chartostr((int)va_arg(ap, intmax_t), f, &size);
	else if (ft_tolower(*(f->type)) == 's')
		number = ft_wstrtostr((char *)va_arg(ap, void *), f, &size);
	/*if (f->width && f->width->max == 0 && ((ft_isnumeric(*(f->type)) 
		&& (!(ft_strcmp(number, "0")))) || ft_tolower(*(f->type)) == 's'))
	{
		//ft_putstr("size 0");
		//size = 0;
	}*/
	ft_padandprint(&number, &f, written, &size);
	//memdel(&f);
	return (number);
}
/*
int		main()
{
	int			written = 0;
	//setlocale(LC_ALL, "");
	//long long	D = -2147;
	char c = 'A';
//	wchar_t c = 945;
	const char	*format = "c";
	//printf("%-1%");
	//printf("printf %#10lx\n", (unsigned long)&c );
	//printf("printf %20p\n", &c );
	ft_convert(&format, &written, c);
//	printf("printf : [%p]", &c);
	//ft_putnbr(printf("%D\n", 2147));
	return (0);
}
*/
