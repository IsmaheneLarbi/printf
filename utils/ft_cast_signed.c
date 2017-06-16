/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cast_signed.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilarbi <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/25 16:09:48 by ilarbi            #+#    #+#             */
/*   Updated: 2017/06/16 13:12:36 by ilarbi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "../ft_printf.h"

char	*ft_cast_signed(intmax_t result, t_format *f)
{
	char	*number;

	if (!f || || result < INTMAX_MIN || result > INTMAX_MAX)
		return (NULL);
	if ((f->len && ((f->len->hh && (result < CHAR_MIN || result > CHAR_MAX))
		|| (f->len->h && (result < SHRT_MIN || result > SHRT_MAX)) ||
	   	(f->len->l && (result < LONG_MIN || result > LONG_MAX)) ||
	   	(f->len->ll && (result < LLONG_MIN || result > LLONG_MAX)) ||
	   	(f->len->j && (result < INTMAX_MIN || result > INTMAX_MAX)) ||
	   (f->len->z && (result < LLONG_MIN || result > LLONG_MAX))))
		|| (!(f->len) && (result < INT_MIN || result > INT_MAX)))
	exit(-1);
	if (!f->len || (f->len && (f->len->hh || f->len->h)))
		number = ft_cast_signed_(result);
	else
		number = ft_itoa_max_base(result, ft_assign_base(f));
	return (number);
}
/*
int		main()
{
	t_format	*f;
	intmax_t	hechhech;
	//char		hh;

	f = ft_memalloc(sizeof(t_format));
	f->len = ft_memalloc(sizeof(t_len));
	f->len->hh = 1;
	hechhech = 97;
	printf("%s\n", ft_cast_signed(hechhech, f));	
	return (0);
}*/
