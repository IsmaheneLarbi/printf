/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cast_unsigned_h.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilarbi <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/26 15:14:06 by ilarbi            #+#    #+#             */
/*   Updated: 2017/06/26 16:07:24 by ilarbi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

char	*ft_cast_unsigned_h(uintmax_t result, int base)
{
	unsigned short	ush;
	char			*number;

	//if ((unsigned int)result > USHRT_MAX)
	//	return (NULL);
	ush = (unsigned short)result;
	number = ft_uitoa_max_base(ush, base);
	return (number);
}
