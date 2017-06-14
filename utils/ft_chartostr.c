/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_chartostr.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilarbi <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/02 14:25:55 by ilarbi            #+#    #+#             */
/*   Updated: 2017/06/14 20:03:30 by ilarbi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

char	*ft_c(intmax_t result, t_format *f)
{
	char	*c;

	c = NULL;
	if (MB_CUR_MAX == 1 && (result < 0 || result >= 255))
		exit(-1);
	if (!f || (f && f->len && !(f->len->l)))
		exit(-1);
	if (f->len && f->len->l)
		c = ft_wchart((wint_t)result);
	else if (!(f->len))
	{
		c = ft_strnew(1);
		*c = (unsigned char)result;
	}
	return (c);
}
