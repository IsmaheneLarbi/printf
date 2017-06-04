/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putwchar.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilarbi <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/03 17:47:33 by ilarbi            #+#    #+#             */
/*   Updated: 2017/06/04 14:29:39 by ilarbi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "../ft_printf.h"

void	ft_putwchar(wchar_t letter)
{
	int		i;
	char	**wc;
	int		tab[4];

	i = 0;
	wc = ft_strsplit(ft_wchart(letter), ' ');
	if (letter > 127 && letter < 256 && MB_CUR_MAX == 1)
		write(1, (char *)&letter, 1);
	while (wc[i])
	{
		tab[i] = ft_bin_to_dec(wc[i]);
		write(1, &tab[i], 1);
		i++;
	}
}
/*
int		main()
{
	ft_putwchar(732);
	write(1, "\n",1);
	return (0);
}
*/
