/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilarbi <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/12 11:21:30 by ilarbi            #+#    #+#             */
/*   Updated: 2017/06/16 13:16:37 by ilarbi           ###   ########.fr       */
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
		&& (!ft_issigned(*(f->type))))
		exit(-1);
	if (f->flags && f->flags->hash && (ft_tolower(*(f->type)) != 'x')
	   && (ft_tolower(*(f->type)) != 'o'))
		exit(-1);
	if (!ft_isnumeric(*(f->type)) && f->flags && f->flags->zero)
		exit(-1);
	if (ft_isnumeric(*(f->type)) && f->width && f->flags && (f->width->max >= 0)
		&& f->flags->zero)
		f->flags->zero = 0;
	if ((ft_tolower(*(f->type)) == 'c' || *(f->type) == 'p') && f->width
		&& f->width->max >= 0)
		exit(-1);
	if (f->len && (f->len->hh + f->len->h + f->len->l + f->len->ll 
		+ f->len->j + f->len->z) > 1)
		exit(-1);
	if (f->len && ((!f->len->l && (*(f->type) == 's' || *(f->type) == 'c'))))
		exit(-1);
	else
		ft_putstr("check\n");
}
