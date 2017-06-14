/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_padandprint.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilarbi <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/08 14:22:07 by ilarbi            #+#    #+#             */
/*   Updated: 2017/06/14 17:32:30 by ilarbi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_padandprint(char *str, t_format *f, int *written)
{
	if (!str || !f || !written)
		return ;
	if (ft_tolower(*(f->type)) == 'd' || *(f->type) == 'i')
	{	if (f->width && f->width->max == 0 && *str == '0')
		{
			ft_putchar(' ');
			*written += 1;
		}
		else
		{
			ft_putstr(str);
			*written += *written + ft_strlen(str);
		}
	}
}
