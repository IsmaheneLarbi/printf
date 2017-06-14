/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_wstrtostr.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilarbi <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/03 19:47:36 by ilarbi            #+#    #+#             */
/*   Updated: 2017/06/14 20:03:54 by ilarbi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

char	*ft_wstrtostr(void *str, t_format *f)
{
	if (!f || (f->len && !(f->len->l)))
		exit(-1);
	if (f->len && f->len->l)
		return (ft_wstr((wchar_t *)str));
	if (!(f->len))
		return ((char *)str);
	return (NULL);
}
