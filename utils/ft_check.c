/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilarbi <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/12 11:21:30 by ilarbi            #+#    #+#             */
/*   Updated: 2017/07/19 17:44:37 by ilarbi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

int		ft_check(t_format **f)
{
	if (!*f)
		{//ft_putstr("1\n");
			return (0);}
	if ((ft_tolower(*((*f)->type)) == 's' || ft_tolower(*((*f)->type)) == 'c')
		&& (*f)->flags	&& ((*f)->flags->hash 
		|| (*f)->flags->plus || (*f)->flags->space || (*f)->flags->zero))
		{ft_putstr("2\n");return (0);}
//	if ((*f)->flags && ((*f)->flags->space || (*f)->flags->plus) 
//		&& ((!ft_issigned(*((*f)->type)) && (*((*f)->type) != '%'))))
//		{ft_putstr("3\n");return (0);}
	if ((*f)->flags && (*f)->flags->hash && (ft_tolower(*((*f)->type)) != 'x')
	   && (ft_tolower(*((*f)->type)) != 'o'))
		{ft_putstr("4\n");return (0);}
	if (!ft_isnumeric(*((*f)->type)) && *((*f)->type) != '%' && (*f)->flags && (*f)->flags->zero)
		{ft_putstr("5\n");return (0);}
	if (ft_isnumeric(*((*f)->type)) && (*f)->width && (*f)->flags 
		&& (((*f)->width->max >= 0 || (*f)->width->precision)) 
		&& (*f)->flags->zero)
		(*f)->flags->zero = 0;
	if (*((*f)->type) == '%' && (*f)->flags && (*f)->flags->hash)
		(*f)->flags->hash = 0;
	if ((ft_tolower(*((*f)->type)) == 'c' || *((*f)->type) == 'p') 
			&& (*f)->width && (*f)->width->max >= 0)
		{ft_putstr("6\n");return (0);}
	if ((*f)->len && ((*f)->len->hh + (*f)->len->h + (*f)->len->l 
		+ (*f)->len->ll	+ (*f)->len->j + (*f)->len->z) > 1)
		{ft_putstr("7\n");return (0);}
	if ((*f)->len && (!((*f)->len->l) && (*((*f)->type) == 's' 
		|| *((*f)->type) == 'c')))
		{ft_putstr("8\n");return (0);}
	if (ft_isunsigned(*((*f)->type)) && (*f)->flags && (*f)->flags->space)
		(*f)->flags->space = 0;
	if (ft_isunsigned(*((*f)->type)) && (*f)->flags && (*f)->flags->plus)
		(*f)->flags->plus = 0;
	if ((*f)->flags)
	{
		(((*f)->flags->plus && (*f)->flags->space) ? (*f)->flags->space = 0 : 0);
		(((*f)->flags->minus && (*f)->flags->zero) ? (*f)->flags->zero = 0 : 0);
	}
	return (1);
}
