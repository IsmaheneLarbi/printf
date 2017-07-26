/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_redirect_p.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilarbi <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/20 13:10:44 by ilarbi            #+#    #+#             */
/*   Updated: 2017/07/25 20:22:20 by ilarbi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"
/*add p to list of types accepted and ft_check and ft_padandprint*/
char	*ft_redirect_p(t_format **f, void *address, int *size)
{
	char			*number;
	unsigned long 	add;

	if (!*f || !size)
		return (NULL);
	add = (unsigned long)address;
//	(*f)->type = ft_strnew(1);
//	ft_strcpy((*f)->type, "x");
//	if (!((*f)->flags) && !((*f)->flags = ft_memalloc(sizeof(t_flags))))
//		return (NULL);
//	(*f)->flags->hash = 1;
//	if (!((*f)->len) && !((*f)->len = ft_memalloc(sizeof(t_len))))
//		return (NULL);
	//(*f)->len->l = 1;
	//number = ft_cast_unsigned_l(add, ft_assign_base(*f));
	number = ft_cast_unsigned_l(add, 16);
//	if (*number == '0')
//		number = ft_strjoin_free(ft_strdup("0x"), 1, number, 1);
	ft_strminimalize(&number);
	*size = ft_strlen(number);
	return (number);
}
