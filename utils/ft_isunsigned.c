/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isunsigned.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilarbi <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/27 15:43:22 by ilarbi            #+#    #+#             */
/*   Updated: 2017/06/14 15:28:52 by ilarbi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

int		ft_isunsigned(char type)
{
	if (!type)
		return (-1);
	return ((ft_tolower(type) == 'o' || ft_tolower(type) == 'u' ||
				ft_tolower(type) == 'x') ? 1 : 0);
}
