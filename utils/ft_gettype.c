/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_gettype.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilarbi <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/17 20:42:20 by ilarbi            #+#    #+#             */
/*   Updated: 2017/05/27 18:17:44 by ilarbi           ###   ########.fr       */
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
