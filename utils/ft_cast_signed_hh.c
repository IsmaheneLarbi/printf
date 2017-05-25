/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cast_signed_hh.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilarbi <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/25 16:10:17 by ilarbi            #+#    #+#             */
/*   Updated: 2017/05/25 22:58:04 by ilarbi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "../ft_printf.h"

char	*ft_cast_signed_hh(intmax_t result)
{
	char	*number;
	
	number = ft_strnew(1);
	*number	= (char)result;
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
