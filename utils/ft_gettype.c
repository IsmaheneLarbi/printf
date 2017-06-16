/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_gettype.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilarbi <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/17 20:42:20 by ilarbi            #+#    #+#             */
/*   Updated: 2017/06/16 14:08:07 by ilarbi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"
#include "../ft_printf.h"

void	ft_gettype(const char **format, t_format **f)
{
	if (!format || !*format || !f || !*f)
		exit(-1) ;
	if (*(*format) && ft_isok(*(*format)))
	{
		if (ft_istype(*(*format)))
		{
			(*f)->type = ft_strnew(1);
			*((*f)->type) = *(*format);
		}
		if (*(*format) == '%')
		{
			if (f->flags && f->flags->hash)
				f->flags->hash = 0;
			ft_padandprint(&f, "%");	
			//->padding(w, flags)
			//->print, return
		}	
	}
	else
	{
		ft_memdel((void **)f);
		ft_putstr("no type\n");
		exit(-1);
	}
}
