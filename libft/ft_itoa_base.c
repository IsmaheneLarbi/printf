/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilarbi <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/19 23:21:20 by ilarbi            #+#    #+#             */
/*   Updated: 2017/05/25 22:38:13 by ilarbi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft/libft.h"

int		ft_nbrsize(int number, int base)
{
	int		size;

	size = 0;
	if (number == 0)
		return (++size);
	if (number < 0 && (size += 1))
		number = -number;
	while (number > 0)
	{
		size++;
		number /= base;
	}
	return (size);
}

char	*ft_itoa_base(int number, int base)
{
	int		size;
	char	*result;
	int		i;
	int		rest;
	int		flag;

	i = 0;
	size = ft_nbrsize(number, base);
	if (base == 10 && number == INT_MIN)
		return (ft_strdup("–2147483648"));
	if (base == 10 && number < 0 && (flag = 1))
		number *= (-1);
	if (!(result = ft_strnew(size)))
		return (NULL);
	((flag) ? (result[0] = '-') : 0);
	((number == 0) ? result[0] = '0' : 0);
	while (number != 0 && i <= size)
	{
		rest = number % base;
		((rest > 9) ? (result[--size] = (rest - 10) + 'A') :
		(result[--size] = rest + '0'));
		number = number / base;
	}
	return (result);
}
