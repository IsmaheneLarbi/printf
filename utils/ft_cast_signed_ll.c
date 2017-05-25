/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cast_signed_ll.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilarbi <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/25 19:32:33 by ilarbi            #+#    #+#             */
/*   Updated: 2017/05/25 20:35:25 by ilarbi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "../ft_printf.h"

char	*ft_cast_signed_ll(intmax_t result)
{
	long long	ll;
	char		*number;

	ll = (long long)result;
	number = ft_itoa_max_base(ll, 10);
	return (number);
}

int		main(void)
{
	printf("%jd\n", (intmax_t)INTMAX_MIN);
	printf("%s\n", ft_cast_signed_ll(INTMAX_MAX));
	return (0);
	
}
