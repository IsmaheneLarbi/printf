/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cast_unsigned.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilarbi <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/26 15:05:08 by ilarbi            #+#    #+#             */
/*   Updated: 2017/06/16 12:55:49 by ilarbi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "../ft_printf.h"

/*
**ameliorer avec fct (flags, w, len, type) qui fait tt
*/ 
char	*ft_cast_unsigned(uintmax_t result, t_format *f)
{
	char	*number;
	if (!f || !(f->type) || result > UINTMAX_MAX)
		return (NULL);
	if (*(f->type) == 'p')
	{
		f->type = "x";
		if (!f->len && !(f->len = ft_memalloc(sizeof(t_len))))
			exit(-1);
		f->len->l = 1;
		if (!f->flags && !(f->flags = ft_memalloc(sizeof(t_flags))))
			exit(-1);
		f->flags->hash = 1;
	}
	if (!(f->len) || (f->len && (f->len->hh || f->len->h)))
		number = ft_cast_unsigned_(result, ft_assign_base(f));
	else
		number = ft_uitoa_max_base(result, ft_assign_base(f));
	return ((*(f->type) == 'x') ? ft_strminimalize(&number) : number);
}
/*
int		main()
{
	t_format	*f = ft_memalloc(sizeof(t_format));
	f->len = ft_memalloc(sizeof(t_len));
	f->type = ft_strnew(1);
	f->type = "x";
	f->len->j = 1;
	intmax_t	result = 2;
	printf("%s\n", ft_cast_unsigned(result, f));
	return (0);
}*/
