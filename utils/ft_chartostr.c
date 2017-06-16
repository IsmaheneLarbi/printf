/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_chartostr.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilarbi <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/02 14:25:55 by ilarbi            #+#    #+#             */
/*   Updated: 2017/06/16 12:35:28 by ilarbi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

char	*ft_chartostr(intmax_t result, t_format *f)
{
	char	*c;

	c = NULL;
	if (MB_CUR_MAX == 1 && (result < 0 || result >= 255))
		exit(-1);
	if (!f)
		exit(-1);
	if (f->len  && result < INT_MIN && result > INT_MAX)
	   exit(-1);	
	if (f->len || *(f->type) == 'C')
		c = ft_wchart((int)result);
	else if (!(f->len))
	{
		c = ft_strnew(1);
		*c = (unsigned char)result;
	}
	return (c);
}
