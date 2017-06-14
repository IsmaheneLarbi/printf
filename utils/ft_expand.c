/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_expand.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilarbi <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/14 15:21:19 by ilarbi            #+#    #+#             */
/*   Updated: 2017/06/14 16:15:46 by ilarbi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

int		ft_expand(char **result, , char type , int max)
{
	char	*sign;
	int		i;
	int		size;
	int		fldsize;

	i = 0;
	if (ft_isnumeric(type))
	{
		size = ft_strlen(result);
		size = ((*(*result) == '+' || *(*result) == '-') ? size - 1 : size);
		if (*(*result) == '-' || *(*result) == '+')
		{
			fldsize = ((max > size) ? (max + 1) : (size + 1))
			sign = ft_strnew(fldsize);
			*sign++ = *(*result);
			while (max > size  && i++ < max)
				*sign++ = '0';
			*result = ft_strjoin_free(*sign, 1, (*result) + 1);
		}
		else
			fldsize = ((max > size) ? (max) : size);
		
	}
	return fldsize;
}
