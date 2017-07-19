/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parse.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilarbi <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/04 21:41:15 by ilarbi            #+#    #+#             */
/*   Updated: 2017/07/19 22:41:00 by ilarbi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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
		if (f)
			ft_fdel(&f);
		f = NULL;
	}
	return (f);
}
