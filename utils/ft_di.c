/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_di.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilarbi <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/20 19:04:40 by ilarbi            #+#    #+#             */
/*   Updated: 2017/05/26 14:16:50 by ilarbi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
/*
 **itoa fait un malloc =>free
 */
char	*ft_di(t_format **f, intmax_t result, int *written)
{
	char	res;
	short	sh;
	char	*ret;

	if (!f || !*f)
	   return (-1);	
	if ((*f)->len && (*f)->len->hh)
	{
		res = (char)result;
		ret = ft_itoa(res);
		write(1, (char *)ret, 1); 
		(*written++);
	}
	if ((*f)->len && (*f)->len->h)
	{
		sh = (short)result;

	}
}
