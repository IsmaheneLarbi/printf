/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parse.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilarbi <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/04 21:41:15 by ilarbi            #+#    #+#             */
/*   Updated: 2017/05/14 21:35:23 by ilarbi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <stdio.h>
#include "ft_printf.h"

void		ft_checkforflags(const char **format, t_format **f)
{
	if (!*format || !f || !*f) 
		exit(-1);
	if (!*(*format) || (!ft_isflag(*(*format)) && *(*format) != '%'))
		(*f)->flags = NULL;
	else {
		if (ft_isflag(*(*format)) && (!((*f)->flags = (t_flags *)ft_memalloc(sizeof(t_flags)))))
			exit(-1);
		while (*(*format) && (ft_isflag(*(*format)) || *(*format) == '%'))
		{
			if (*(*format) == '0')
				(*f)->flags->zero = 1;
			if (*(*format) == '-')
				(*f)->flags->minus = 1;
			if (*(*format) == '+')
				(*f)->flags->plus = 1;
			if (*(*format) == '#')
				(*f)->flags->hash = 1;
			if (*(*format) == ' ')
				(*f)->flags->space = 1;
			if (*(*format) == '%' && *(*format - 1) != '%')
			{
				ft_memset((*f)->flags, 0, sizeof(t_flags));
				return;	
			}(*format)++;
		}
		(((*f)->flags->plus && (*f)->flags->space) ? (*f)->flags->space = 0 : 0);
		(((*f)->flags->minus && (*f)->flags->zero) ? (*f)->flags->zero = 0 : 0);
	}
}

void		ft_checkforwidth(const char **fr, t_format **f)
{

	if (!fr || !*fr)
		exit(-1);
	if (!ft_isdigit(*(*fr)) || *(*fr) != '+' || *(*fr) != '.')
		(*f)->width = NULL;
	else
	{
		if (!((*f)->width = (t_width *)ft_memalloc(sizeof(t_width))))
			exit(-1);
		while (*fr && ((ft_isdigit(*(*fr)) || *(*fr) == '.' || (*(*fr) == '+'))))
		{
			if (*(*fr) == '.')
			{
				(*f)->width->precision = 1;
				(*fr)++;
			}
			else
				(((*f)->width->precision == 1) ? ((*f)->width->max = ft_atoistr(fr)) :
				 ((*f)->width->min = ft_atoistr(fr)));
		}
	}
}

void		ft_checkforlen(const char **fr, t_format **f)
{
	int	pos;

	pos = 0;
	if (!*fr)
		exit(-1);

	 if (!ft_islen(*(*fr))) 
		 (*f)->len = NULL;
	 else
	 {

		 (((*f)->len = ft_memalloc(sizeof(t_len))) ? (*f)->len : exit(-1));
		if (*(*fr + 1) && ft_istype(*(*fr + 1))) 
		{
			((*(*fr) == 'j') ? ((*f)->len->j = 1) : (*f)->len->j);
			((*(*fr) == 'z') ? ((*f)->len->z = 1) : (*f)->len->z);
			((*(*fr) == 'l') ? ((*f)->len->l = 1) : (*f)->len->l);
			((*(*fr) == 'h') ? ((*f)->len->h = 1) : (*f)->len->h);
			(*fr)++;
		}
		else if (*(*fr + 2) && ft_istype(*(*fr + 2)))
		{
			((ft_strncmp(*fr, "hh", 2)) ? ((*f)->len->hh = 1) : (*f)->len->hh);
			((ft_strncmp(*fr, "ll", 2)) ? ((*f)->len->ll = 1) :(*f)->len->ll);
			*fr = *fr + 2;
		}
		else
			exit(-1);
	 }
}

t_format	*ft_parse(const char **format)
{
	t_format *f;

	if (!(f = ft_memalloc(sizeof(t_format))))
		exit(-1);
	ft_checkforflags(format, &f);
	ft_checkforwidth(format, &f);
	ft_checkforlen(format, &f);
	ft_printformat(f);
	return (f);
}
