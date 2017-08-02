/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parse.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilarbi <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/04 21:41:15 by ilarbi            #+#    #+#             */
/*   Updated: 2017/08/02 18:59:48 by ilarbi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <stdio.h>
#include "ft_printf.h"

t_format	*ft_parse(const char **format, int *written)
{
	t_format	*f;

	if (!(f = ft_memalloc(sizeof(t_format))))
		exit(-1);
	ft_checkforflags(format, &f);
	ft_checkforwidth(format, &f);
	ft_checkforlen(format, &f);
	ft_gettype(format, &f);
	//ft_printformat(f);
	//printf("parse | ft_check result : %d | f : %p\n", ft_check(&f), f);
	if (f && f->type && ft_isok(*(f->type)) && !ft_check(&f))
	{
		if (ft_istype(*(f->type)))//UB
			*written = -1;
		ft_fdel(&f);
		f = NULL;

	}
	//ft_printformat(f);
	return (f);
}
