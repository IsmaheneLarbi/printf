/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_nbrusize.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilarbi <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/25 17:09:10 by ilarbi            #+#    #+#             */
/*   Updated: 2017/05/25 17:29:17 by ilarbi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_nbrusize(uintmax_t number, int base)
{
	int	size;

	size = 0;
	if (number == 0)
		return (size++);
	while (number > 0)
	{
		size++;
		number /= base;
	}
	return (size);
}
