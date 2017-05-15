/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilarbi <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/05 14:48:04 by ilarbi            #+#    #+#             */
/*   Updated: 2017/05/14 22:33:31 by ilarbi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
/*
void	ft_getvar()
{
	
}
*/
void	ft_convert(const char **format, int *written)
{
	ft_parse(format);
	(*written)++;
	//memdel(&f);
}
