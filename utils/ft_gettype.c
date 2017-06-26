/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_gettype.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilarbi <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/17 20:42:20 by ilarbi            #+#    #+#             */
/*   Updated: 2017/06/21 19:04:44 by ilarbi           ###   ########.fr       */
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
		(*f)->type = ft_strnew(1);
		*((*f)->type) = *(*format);
	}
	else
	{
		ft_memdel((void **)f);
		exit(-1);
	}
}
