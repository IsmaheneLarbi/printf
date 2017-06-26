/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cast_signed_hh.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilarbi <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/25 16:10:17 by ilarbi            #+#    #+#             */
/*   Updated: 2017/06/26 21:48:15 by ilarbi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "../ft_printf.h"

char	*ft_cast_signed_hh(intmax_t result)
{
	int		hhd;
	char	*number;

	hhd = (signed char)result;
//	if (hhd < CHAR_MIN || hhd > CHAR_MAX)
//		return (NULL);
	number	= ft_itoa(hhd);
	return (number);
}
/*
int		main(void)
{
	char	*c;
	intmax_t t = -128;

	c = ft_cast_signed_hh(t);
	printf("%c\n", *c);
	return (0);
}*/
