/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cast_unsigned_hh.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilarbi <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/26 15:05:23 by ilarbi            #+#    #+#             */
/*   Updated: 2017/06/20 19:30:39 by ilarbi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "../ft_printf.h"

char	*ft_cast_unsigned_hh(uintmax_t result, int base)
{
	unsigned int	hhu;
	char			*number;

	hhu = (unsigned int)result;
	if (hhu > UCHAR_MAX)
		return (NULL);
	number = ft_uitoa_max_base(hhu, base);
	return (number);
}
