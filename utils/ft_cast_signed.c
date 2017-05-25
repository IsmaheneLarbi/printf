/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cast_signed.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilarbi <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/25 16:09:48 by ilarbi            #+#    #+#             */
/*   Updated: 2017/05/25 23:31:01 by ilarbi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

char	*ft_cast_signed(intmax_t result, t_format *f)
{
	char*	(*fptr)(intmax_t);
	char	*number;

	if (!f || !fptr)
		return (NULL);
	if (!f->len)
		fptr = &ft_cast_signed_;
	else
	{
		((f->len->hh) ? fptr = &ft_cast_signed_hh : 0);
		((f->len->hh) ? fptr = &ft_cast_signed_h : 0);
		((f->len->hh) ? fptr = &ft_cast_signed_l : 0);
		((f->len->hh) ? fptr = &ft_cast_signed_ll : 0);
		((f->len->hh) ? fptr = &ft_cast_signed_z : 0);
	}
	number = fptr(result);
	return (number);
}

int		main()
{
	t_format	*f;
	intmax_t	hechhech;
	char		hh;

	f = ft_memalloc(sizeof(t_format));
	f->len = ft_memalloc(sizeof(t_len));
	f->len->hh = 1;
	hechhech = 65;
	printf("%s\n", ft_cast_signed(hechhech, f));	
	return (0);
}
