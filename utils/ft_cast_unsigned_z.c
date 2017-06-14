/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cast_unsigned_z.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilarbi <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/26 15:36:20 by ilarbi            #+#    #+#             */
/*   Updated: 2017/05/28 17:59:20 by ilarbi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

char	*ft_cast_unsigned_z(uintmax_t result, int base)
{
	size_t	zu;
	char	*number;

	zu = (size_t)result;
	number = ft_uitoa_max_base(zu, base);
	return (number);
}
