/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cast_signed_l.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilarbi <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/25 17:41:48 by ilarbi            #+#    #+#             */
/*   Updated: 2017/05/26 15:40:21 by ilarbi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "../ft_printf.h"

char	*ft_cast_signed_l(intmax_t result)
{
	long	l;
	char	*number;

	l = (long)result;
	number = ft_itoa_max_base(l, 10);
	return (number);
}
/*
int		main()
{
	//intmax_t l = -9223372036854775808;
	printf("%s\n",ft_cast_signed_l(2147483647)); 
	return (0);
}*/
