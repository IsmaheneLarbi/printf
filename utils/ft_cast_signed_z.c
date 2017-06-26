/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cast_signed_z.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilarbi <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/25 19:32:33 by ilarbi            #+#    #+#             */
/*   Updated: 2017/06/26 21:49:58 by ilarbi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

char	*ft_cast_signed_z(intmax_t result)
{
	ssize_t		z;
	char		*number;

	z = (ssize_t)result;
//	if ((long long)result < LLONG_MIN || (long long)result > LLONG_MAX)
//		return (NULL);
	number = ft_itoa_max_base(z, 10);
	return (number);
}
/*
int		main(void)
{
	printf("%llu\n", SIZE_MAX);
	printf("%s\n", ft_cast_signed_z(INTMAX_MAX));
	return(0);
}*/
