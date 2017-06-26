/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cast_signed_.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilarbi <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/25 22:27:27 by ilarbi            #+#    #+#             */
/*   Updated: 2017/06/26 12:46:54 by ilarbi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

char	*ft_cast_signed_(intmax_t result)
{
	int		r;
	char	*number;

	r = (int)result;
	if (r < INT_MIN || r > INT_MAX)
		return (NULL);
	number = ft_itoa_base(r, 10);
	return (number);
}
