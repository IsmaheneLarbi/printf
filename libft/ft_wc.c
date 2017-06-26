/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_wc.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilarbi <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/14 18:49:21 by ilarbi            #+#    #+#             */
/*   Updated: 2017/06/24 19:21:43 by ilarbi           ###   ########.fr       */
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
	if (!letter)
		return (NULL);
	wc = ft_strsplit(letter, ' ');
	if (!(tab = (char *)malloc(sizeof(char) * 4)))
		exit(-1);
	while (wc[i])
	{
		tab[i] = (char)malloc(sizeof(char));
		tab[i] = ft_bin_to_dec(wc[i]);
		free(wc[i]);
		i++;
	}
	free(wc);
	return (tab);
}
/*
int		main()
{
	char *tab;
	int	i = 0;
	int size = ft_wcsize(129);
	setlocale(LC_ALL, "");
	printf("printf : [%lc]\n", 129);
	tab = ft_wc(ft_wchart(129));
	while (i < size)
		write(1, &tab[i++], 1);
	return (0);
}*/
