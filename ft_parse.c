/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parse.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilarbi <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/04 21:41:15 by ilarbi            #+#    #+#             */
/*   Updated: 2017/06/26 16:15:02 by ilarbi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "utils/utils.h"
#include "ft_printf.h"

t_format	*ft_parse(const char **format)
{
	t_format	*f;

	if (!(f = ft_memalloc(sizeof(t_format))))
		exit(-1);
	ft_checkforflags(format, &f);
	ft_checkforwidth(format, &f);
	ft_checkforlen(format, &f);
	ft_gettype(format, &f);
	//ft_printformat(f);
	if (!ft_check(&f))
	{
		ft_putstr("parse !check\n");
		ft_fdel(&f);
	}
	return (f);
}
/*
int		main()
{
	const char *format = "#10lC";
	ft_parse(&format);
	return (0);
}*/
