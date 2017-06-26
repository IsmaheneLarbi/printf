/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printstr.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilarbi <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/22 19:12:52 by ilarbi            #+#    #+#             */
/*   Updated: 2017/06/22 19:17:33 by ilarbi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

void	ft_printstr(char **s, int *written)
{
	if (!*s || !written)
		return ;
	((*(*s) ==  '-') ? ft_putstr(*s + 1) : ft_putstr(*s));
	((*(*s) == '-') ? (*written += (ft_strlen(*s) - 1)) 
	 : (*written += ft_strlen(*s)));
}
