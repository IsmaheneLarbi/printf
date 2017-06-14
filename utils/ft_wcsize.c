/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_wcsize.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilarbi <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/03 18:10:29 by ilarbi            #+#    #+#             */
/*   Updated: 2017/06/13 14:13:24 by ilarbi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

int		ft_wcsize(wchar_t letter)
{
	int		bits;

	bits = ft_strlen(ft_itoa_base((wint_t)letter, 2));
	if (bits <= 7)
		return (1);
    else if (bits <= 11)
		return (2);
    else if (bits <= 16)
		return (3);
    else if (bits <= 21)
		return (4);
    else
		return (-1);	
}
