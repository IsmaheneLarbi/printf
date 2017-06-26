/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fdel.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilarbi <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/24 14:17:17 by ilarbi            #+#    #+#             */
/*   Updated: 2017/06/24 14:17:47 by ilarbi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

void		ft_fdel(t_format **f)
{
	if (!(*f))
		return ;
	if ((*f)->flags)
	{
		free((*f)->flags);
		printf("flags freed\n");
	}
	if ((*f)->width)
	{
		free((*f)->width);
		printf("width freed\n");
	}
	if ((*f)->len)
	{
		free((*f)->len);
		printf("len freed\n");
	}
	free(*f);
	exit(-1);
}
