/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_wstr.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilarbi <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/02 13:54:16 by ilarbi            #+#    #+#             */
/*   Updated: 2017/06/23 19:19:12 by ilarbi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

char	*ft_wstr(wchar_t *ws)
{
	char	*str;
	char	*(*fptr)(wchar_t);
	wchar_t	*cur;

	if (!(str = ft_memalloc(1024)))
		exit(-1);
	fptr = &ft_wchart;
	cur = ws;
	if (!ws)
		exit(-1);
	while (*cur)
		ft_strjoin_free(str, 1, (fptr)(*cur++), 1);
	return (str);
}
/*
int		main()
{
	wchar_t	*s = L"我是一只猫。";
	while (*s)
		ft_putwchar(*s++);
	return (0);
}*/
