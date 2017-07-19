/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_redirect_p.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilarbi <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/20 13:10:44 by ilarbi            #+#    #+#             */
/*   Updated: 2017/06/26 14:51:21 by ilarbi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

char	*ft_redirect_p(t_format **f, void *address, int *size)
{
	char			*number;
	unsigned long 	add;

	if (!*f || !size)
		return (NULL);
	add = (unsigned long)address;
	//if (address == NULL && (*size = ft_strlen("(null)")))
	//	return (ft_strdup("(null)"));
//	if (add > ULONG_MAX)
//		return (NULL);
	(*f)->type = ft_strnew(1);
	ft_strcpy((*f)->type, "x");
	if (!((*f)->flags = ft_memalloc(sizeof(t_flags))))
		return (NULL);
	(*f)->flags->hash = 1;
	if (!((*f)->len = ft_memalloc(sizeof(t_len))))
		return (NULL);
	(*f)->len->l = 1;
	number = ft_cast_unsigned_l(add, ft_assign_base(*f));
	if (*number == '0')
		number = ft_strjoin_free(ft_strdup("0x"), 1, number, 1);
	ft_strminimalize(&number);
	*size = ft_strlen(number);
	return (number);
}
/*
int		main()
{
	t_format *f = ft_memalloc(sizeof(t_format));
	int a;
	printf("&a : %#lx\n", (unsigned long)&a);
	printf("%s\n", ft_redirect_p(&f, &a));
	return (0);
}*/
