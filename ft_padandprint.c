/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_padandprint.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilarbi <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/08 14:22:07 by ilarbi            #+#    #+#             */
/*   Updated: 2017/06/16 14:24:49 by ilarbi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_padandprint(char **str, t_format **f, int *written)
{
	int		fldsize;
	char	signtype;

	fldsize = 0;
	signtype = ' ';
	if (!str || !f || !*str || !*f || !written)
		return ;
	if (ft_issigned(*((*f)->type)) && (*f)->width && !((*f)->width->max)
		&& *(*str) == '0')
		{
			ft_memdel(f);
			ft_strdel(str);
			return ;
		}
	if (ft_issigned(*((*f)->type)))
		fldsize = max;
	if (f->flags->hash)
		signtype = *((*f)->type);
	else if (*(*str) == '-')
		signtype = '-';
	else if (f->flags && f->flags->plus)
		signtype = '+';
	ft_putstr(str);
	*written += *written + ft_strlen(str);
}
