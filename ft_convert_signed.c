/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert_signed.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilarbi <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/20 21:56:02 by ilarbi            #+#    #+#             */
/*   Updated: 2017/06/13 14:38:52 by ilarbi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "ft_printf.h"

/*
 **check before that current char is not null
 **only for d, i conversion specifiers
 **with all the length modifiers
 **j needs no cast, already intmax_t
 */

intmax_t	ft_convert_signed(char **format, ...)
{
	va_list		ap;
	intmax_t	result;

	if (!format || !*format)
		return (-1);
	va_start(ap, format);
	result = va_arg(ap, intmax_t);
	va_end(ap);
	(*format)++;
	return (result);
}

/*void	ft_cast_signed(intmax_t result, t_format **f, int *written)
{
	char	r;

	if (!f || !*f || !written)
		return ;
	if ((*f)->len)
	{
	}
}*/
/*
int		main(void)
{
	char		*format;
	t_format 	*f;
	int			written;

	written = 0;

	if (!(f = (t_format *)ft_memalloc(sizeof(t_format))))
		exit(-1);

	if (!(f->len = (t_len *)ft_memalloc(sizeof(t_len))))
		exit(-1);
	f->len->hh = 1;

	format = "d";

	intmax_t t = 65;
	printf("%jd | %c\n", ft_convert_signed(&format,t), *format);
//	ft_cast_signed(t, &f, &written);
	return (0);
}*/
