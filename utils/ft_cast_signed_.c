/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cast_signed_.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilarbi <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/25 22:27:27 by ilarbi            #+#    #+#             */
/*   Updated: 2017/06/30 22:01:15 by ilarbi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

char	*ft_cast_signed_(int result)
{
	char	*number;

	//if (r < INT_MIN || r > INT_MAX)
	//	return (NULL);
	number = ft_itoa_base(result, 10);
	return (number);
}
