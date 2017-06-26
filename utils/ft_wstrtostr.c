/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_wstrtostr.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilarbi <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/03 19:47:36 by ilarbi            #+#    #+#             */
/*   Updated: 2017/06/26 18:16:51 by ilarbi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

char	*ft_wstrtostr(void *str, t_format *f, int *size)
{
	char *s;

	if (!str || !f || (f->len && !(f->len->l)))
		exit(-1);
	s = NULL;
	if ((f->len && f->len->l) || (*(f->type) == 'S'))
	{
		s = ft_wstr((wchar_t *)str);
		*size = ((f->width && f->width->max > 0 
				&& f->width->max < (int)ft_strlen(s)) 
				? ft_wstrbytes((wchar_t *)str, f->width->max)
				: ft_strlen(s));
	}
	if (!(f->len) && (*(f->type) == 's'))
	{
		s = ft_strnew(ft_strlen((char *)str));
		ft_strcpy(s, str);
		*size = ((f->width && f->width->max >= 0 
				&& ((int)ft_strlen(s) > f->width->max)) 
				? f->width->max : ft_strlen(s));
	}
	return (s);
}
