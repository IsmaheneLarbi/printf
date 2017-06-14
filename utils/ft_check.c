/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilarbi <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/12 11:21:30 by ilarbi            #+#    #+#             */
/*   Updated: 2017/06/14 15:29:45 by ilarbi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//#include "utils.h"
#include "../ft_printf.h"

void	ft_check(t_format *f)
{
	if (!f)
		exit(-1);
	if ((ft_tolower(*(f->type)) == 's' || ft_tolower(*(f->type)) == 'c')
		&& f->flags	&& (f->flags->hash 
		|| f->flags->plus || f->flags->space || f->flags->zero))
		exit(-1);
	if (f->flags && (f->flags->space || f->flags->plus) 
		&& ((ft_tolower(*(f->type)) != 'd') && (*(f->type) != 'i')))
		exit(-1);
	if (f->flags && f->flags->hash && ft_isunsigned(*(f->type)) 
		&& (ft_tolower(*(f->type)) != 'u'))
		exit(-1);
	if (f->len && (f->len->hh + f->len->h + f->len->l + f->len->ll 
		+ f->len->j + f->len->z) > 1)
		exit(-1);
	if (f->width && f->width->precision && ft_tolower(*(f->type) == 'c'))
		exit(-1);
	if (ft_isnumeric(*(f->type)) && f->width && f->flags && !f->width->max
		&& f->flags->zero)
		f->flags->zero = 0;
	else
		ft_putstr("check\n");
}
