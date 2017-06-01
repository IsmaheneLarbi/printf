/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_wchart.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilarbi <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/31 12:33:42 by ilarbi            #+#    #+#             */
/*   Updated: 2017/06/01 14:31:25 by ilarbi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <wchar.h>
#include <locale.h>
#include "../ft_printf.h" 

unsigned int	ft_power(unsigned int base, int ex)
{
	if (ex == 0)
		return (1);
	if (ex == 1)
		return (base);
	if (ex > 1)
		return (base * ft_power(base, ex - 1));
	return (-1);
}

unsigned int	ft_bin_to_dec(char *bin)
{
	int				i;
	int				size;
	unsigned int	result;

	if (!bin)
		exit (-1);
	i = 0;
	size = ft_strlen(bin) - 1;
	result = 0;
	while (i <= size)
	{
		result += ((bin[size - i] - 48) * ft_power(2 , i));
		i++;
	}
	return (result);	
}

char	*ft_wchart_to_bin(char *mask, char *number)
{
	int		size;
	int		szmask;

	if (!mask || !number)
		exit(-1);
	size = ft_strlen(number) - 1;
	szmask = ft_strlen(mask) - 1;
	printf("size : %d\n", szmask + 1);
	while (size >= -1 && szmask >= 0)
	{
		//((mask[szmask] == 'x' && size >= 0) ? (mask[szmask--] = number[size--]) : (szmask--));
		if (size >= 0)
			((mask[szmask] == 'x') ? (mask[szmask--] = number[size--]) : (szmask--));
		if (size == -1 && szmask >= 0)
			((mask[szmask] == 'x') ? (mask[szmask--] = '0') : (szmask--));
		printf("mask renvoye %s | size mask : %d | size n :%d\n", mask, szmask + 1, size + 1);
	}
	return (mask);
}

char	*ft_wchart(wchar_t	letter)
{
	int				size;
	char			*number;
	char			*mask;

	number = ft_itoa_base((int)letter, 2);
	size = ft_strlen(number);
	printf("%d\n", size);
	if (size <= 7 && letter < 256)
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

int		main()
{
	
	//int		i = 0;
	int		size;
	int		bits = ft_strlen(ft_itoa_base(193, 2));
	if (bits <= 7)
		size = 1;
	else if (bits <= 11)
		size = 2;
	else if(bits <= 16)
		size = 3;
	else if (bits <= 21)
		size = 4;
	else
		size = -1;
	printf("%s\n", ft_wchart(193));
	/*char	**n = ft_strsplit(ft_wchart(320), ' ');
	unsigned int	tab[size];
	printf("size %d\n", size);
	while (i < size)
	{
		tab[i] = ft_bin_to_dec(n[i]);
		write(1, &tab[i], 1);
		i++;
	}*/
	return (0);
}
