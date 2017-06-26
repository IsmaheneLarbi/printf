/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cast_unsigned.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilarbi <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/26 15:05:08 by ilarbi            #+#    #+#             */
/*   Updated: 2017/06/26 16:07:09 by ilarbi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

/*
**ameliorer avec fct (flags, w, len, type) qui fait tt
*/ 
char	*ft_cast_unsigned(void *result, t_format *f, int *size)
{
	char	*number;
	if (!f || !(f->type) || !size)//result >UINT_MAX
		return (NULL);
	
	if (!(f->len))
		number = ft_cast_unsigned_((unsigned)result, ft_assign_base(f));
	else
	{
		if (f->len->hh)
			number = ft_cast_unsigned_hh((unsigned)result, ft_assign_base(f));	
		else if (f->len->h)
			number = ft_cast_unsigned_h((unsigned)result, ft_assign_base(f));
		else if (f->len->l)
			number = ft_cast_unsigned_l((unsigned long)result, ft_assign_base(f));
		else if (f->len->ll)
			number = ft_cast_unsigned_ll((unsigned long long)result, ft_assign_base(f));
		else if (f->len->j)
			number = ft_cast_unsigned_j((uintmax_t)result, ft_assign_base(f)); 
		else if (f->len->z)
			number = ft_cast_unsigned_z((unsigned long long)result, ft_assign_base(f));
	}
	*size = ft_strlen(number);
	return ((*(f->type) == 'x') ? ft_strminimalize(&number) : number);
}
/*
int		main()
{
	t_format	*f = ft_memalloc(sizeof(t_format));
	f->len = ft_memalloc(sizeof(t_len));
	f->type = ft_strnew(1);
	ft_strcpy(f->type, "X");
	f->len->j = 1;
	intmax_t	result = 11;
	printf("type : %s\n", f->type);
	printf("%s\n", ft_cast_unsigned(result, f));
	return (0);
}*/
