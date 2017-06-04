/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_nbrsize.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilarbi <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/25 17:09:10 by ilarbi            #+#    #+#             */
/*   Updated: 2017/05/25 17:16:46 by ilarbi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_nbrsize(int number, int base)
{
	int	size;

	size = 0;
	if (number == 0)
		return (size++);
	if (number < 0 && size++)
		number = -number;
	while (number > 0)
	{
		size++;
		number /= base;
	}
	return (size);
}
