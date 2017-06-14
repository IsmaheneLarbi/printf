/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_wc.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilarbi <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/14 18:49:21 by ilarbi            #+#    #+#             */
/*   Updated: 2017/06/14 20:23:02 by ilarbi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <locale.h>
#include <stdio.h>
#include "../ft_printf.h"

char	*ft_wc(char *letter)
{
	int		i;
	char	*tab;
	char	**wc;

	i = 0;
	printf("%s\n", letter);
	wc = ft_strsplit(letter, ' ');
	if (!(tab = (char *)malloc(sizeof(char) * 4)))
		exit(-1);
	while (wc[i])
	{
		tab[i] = (char)malloc(sizeof(char));
		tab[i] = ft_bin_to_dec(wc[i]);
		i++;
	}
	return (tab);
}

int		main()
{
	char *tab;
	int	i = 0;
	int size = ft_wcsize(985);
	setlocale(LC_ALL, "");
	printf("printf : [%lc]\n", 985);
	tab = ft_wc(ft_wchart(985));
	while (i < size)
		write(1, &tab[i++], 1);
	return (0);
}
