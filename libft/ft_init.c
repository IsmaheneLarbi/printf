/* ************************************************************************** */
/*																			  */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilarbi <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/08 17:08:53 by ilarbi            #+#    #+#             */
/*   Updated: 2017/05/08 17:08:53 by ilarbi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

void	ft_init(void **somethg, size_t size)
{
	unsigned char **s;

	s = (unsigned char **)somethg;
	if (somethg && *somethg)
	{
		if (!(*s = (unsigned char *)malloc(size)))
			exit(1);
		ft_memset(*s, 0, size);
	}
}
