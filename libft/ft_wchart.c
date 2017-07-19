/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_wchart.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilarbi <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/31 12:33:42 by ilarbi            #+#    #+#             */
/*   Updated: 2017/07/19 20:03:19 by ilarbi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "../ft_printf.h" 

char	*ft_wchart_to_bin(char **mask, char **number)
{
	int		size;
	int		szmask;

	if (!*mask || !*number)
		exit(-1);
	size = ft_strlen(*number) - 1;
	szmask = ft_strlen(*mask) - 1;
	while (size >= -1 && szmask >= 0)
	{
		if (size >= 0)
			(((*mask)[szmask] == 'x') ? ((*mask)[szmask--] = (*number)[size--]) :
			 (szmask--));
		if (size == -1 && szmask >= 0)
			(((*mask)[szmask] == 'x') ? ((*mask)[szmask--] = '0') : (szmask--));
	}
	ft_strdel(number);
	return (*mask);
}

char	*ft_wchart(wchar_t	letter)
{
	int				size;
	char			*number;
	char			*mask;

	number = ft_itoa_base((int)letter, 2);
	size = ft_strlen(number);
	if (MB_CUR_MAX == 1)
		return ((letter >= 0 && letter < 256) ? (number) : NULL);
	else if (MB_CUR_MAX > 1)
	{
		if (size <= 7 && letter < 128)
			return (number);
		else if (size > 7 && size <= 11)
			mask = ft_strdup("110xxxxx 10xxxxxx");
		else if (size > 11 && size <= 16)
			mask = ft_strdup("1110xxxx 10xxxxxx 10xxxxxx");
		else if (size > 16 && size <= 21)
			mask = ft_strdup("11110xxx 10xxxxxx 10xxxxxx 10xxxxxx");
		else
			exit(-1);
		ft_wchart_to_bin(&mask, &number);
		return (mask);
	}
	return (NULL);
}
/*
int		*ft_wc(char *letter)
{
	int		i;
	int		*tab;
	char	**wc;

	i = 0;
	wc = ft_strsplit(letter, ' ');
	if (!(tab = (int *)malloc(sizeof(int) * 4)))
		exit(-1);
	while (wc[i])
	{
		tab[i] = (int)malloc(sizeof(int));
		tab[i] = ft_bin_to_dec(wc[i]);
		i++;
	}
	return (tab);
}*/
