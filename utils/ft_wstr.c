/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_wstr.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilarbi <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/02 13:54:16 by ilarbi            #+#    #+#             */
/*   Updated: 2017/07/19 21:47:57 by ilarbi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

void	ft_freewc(char **wc)
{
	int		i;

	i = 0;
	while (wc && wc[i])
		free(wc[i++]);
	if (wc)
		free(wc);
}

char	*ft_wstr(wchar_t *ws, t_format *f, int *size)
{
	char	*str;
	char	*(*fptr)(wchar_t, t_format *, int *);
	wchar_t	*cur;

	if (!(str = ft_memalloc(1)))
		exit(-1);
	cur = ws;
	fptr = &ft_chartostr;
	if (!ws)
		exit(-1);
	while (*cur)
	{
		str = ft_strjoin_free(str, 1, (fptr)(*cur++, f, size), 1);
	}
	return (str);
}
/*
int		main()
{
	//wchar_t	*s = L"我是一只猫。";
	wchar_t *s = L"米"; 
	while (*s)
		ft_putwchar(*s++);
	return (0);
}*/
