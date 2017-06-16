/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilarbi <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/05 14:48:04 by ilarbi            #+#    #+#             */
/*   Updated: 2017/06/16 14:05:02 by ilarbi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "utils/utils.h"
#include "ft_printf.h"
/*
void	ft_getvar()
{
	
}
*/
char	*ft_convert(const char **format, int *written, ...)
{
	t_format	*f;
	char		*number;
	va_list		ap;

	va_start(ap, written);
	f = ft_parse(format);
	number = NULL;
	if (f->type && *(f->type) == 'p')
		ft_redirect_p(&f);
	if (f->type && ft_issigned(*(f->type)))
		number = ft_cast_signed(va_arg(ap, intmax_t), f);
	else if (f->type && ft_isunsigned(*(f->type)))
		number = ft_cast_unsigned(va_arg(ap, uintmax_t), f);
	else if (f->type && (ft_tolower(*(f->type)) == 'c'))
		number = ft_chartostr(va_arg(ap, intmax_t), f);
	else if (f->type && (ft_tolower(*(f->type)) == 's'))
		number = ft_wstrtostr(va_arg(ap, void *), f);
	ft_padandprint(number, f, written);
	va_end(ap);
	//memdel(&f);
	return (number);
}
/*
int		main()
{
	int			written = 0;
	//short		D = 2147;
	const char	*format = "1.lc";
	
	ft_convert(&format, &written, 945);
	//printf("wr : %d\n", written);
	//ft_putnbr(printf("%D\n", 2147));
	return (0);
}*/
