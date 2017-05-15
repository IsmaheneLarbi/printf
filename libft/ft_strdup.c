/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilarbi <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/09 18:02:00 by ilarbi            #+#    #+#             */
/*   Updated: 2017/05/01 16:30:15 by ilarbi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

char	*ft_strdup(const char *s1)
{
	int		i;
	int		j;
	char	*copy;

	i = 0;
	j = 0;
	while (s1[i] != '\0')
		i++;
	copy = (char*)malloc(sizeof(char) * (i + 1));
	if (copy == NULL)
		return (copy);
	while (j < i)
	{
		copy[j] = s1[j];
		j++;
	}
	copy[i] = '\0';
	return (copy);
}
