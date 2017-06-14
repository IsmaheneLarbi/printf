/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cast_signed_.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilarbi <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/25 22:27:27 by ilarbi            #+#    #+#             */
/*   Updated: 2017/05/28 18:06:14 by ilarbi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "../ft_printf.h"

char	*ft_cast_signed_(intmax_t result)
{
	int		r;
	char	*number;

	r = (int)result;
	number = ft_itoa_base(r, 10);
	return (number);
}
/*
int		main()
{
	printf("%s\n", ft_cast_signed_(INT_MIN));
	return (0);
}
*/
