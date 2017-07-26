/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_wc.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilarbi <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/14 18:49:21 by ilarbi            #+#    #+#             */
/*   Updated: 2017/07/19 22:45:04 by ilarbi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

/*
**wc = pourquoi allouer 4? allouer wcsize
*/
char	*ft_wc(char *letter)
{
	int		i;
	char	*tab;
	char	**wc;

	i = 0;
	if (!letter)
		return (NULL);
	wc = ft_strsplit(letter, ' ');
	free(letter);
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
