/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_wchart.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilarbi <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/31 12:33:42 by ilarbi            #+#    #+#             */
/*   Updated: 2017/06/14 20:17:14 by ilarbi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h" 

char	*ft_wchart_to_bin(char *mask, char *number)
{
	int		size;
	int		szmask;

	if (!mask || !number)
		exit(-1);
	size = ft_strlen(number) - 1;
	szmask = ft_strlen(mask) - 1;
	while (size >= -1 && szmask >= 0)
	{
		if (size >= 0)
			((mask[szmask] == 'x') ? (mask[szmask--] = number[size--]) : (szmask--));
		if (size == -1 && szmask >= 0)
			((mask[szmask] == 'x') ? (mask[szmask--] = '0') : (szmask--));
	}
	return (mask);
}

char	*ft_wchart(wchar_t	letter)
{
	int				size;
	char			*number;
	char			*mask;


	number = ft_itoa_base((wint_t)letter, 2);
	size = ft_strlen(number);
	if (MB_CUR_MAX == 1)
		return ((letter < 256) ? (number) : NULL);
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
		return (ft_wchart_to_bin(mask, number));
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
/*
int		main()
{
	int	*tab;
	int	i = 0;

	//setlocale(LC_ALL, "");
	printf("printf : [%lc]\n", 185);
	tab = ft_wc(ft_wchart(185));
	while (i < 4)
		write(1, &tab[i++], 1);
	return (0);
}*/
