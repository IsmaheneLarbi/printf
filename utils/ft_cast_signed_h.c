/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cast_signed_h.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilarbi <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/25 16:30:01 by ilarbi            #+#    #+#             */
/*   Updated: 2017/05/26 14:14:35 by ilarbi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "../ft_printf.h"

char	*ft_cast_signed_h(intmax_t result)
{
	short	sh;
	char	*number;
	
	sh = (short)result;
	number = ft_itoa_max_base(sh, 10);
	return (number);
}
/*
int		main(void)
{
	intmax_t sh = -32768;

	printf("%s\n", ft_cast_signed_h(sh));
	return(0);
}*/
