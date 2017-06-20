/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_padandprint.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilarbi <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/08 14:22:07 by ilarbi            #+#    #+#             */
/*   Updated: 2017/06/20 11:43:14 by ilarbi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "ft_printf.h"

int		size(char *str)
{
	return ((*str == '-' || *str == '+') ? (ft_strlen(str) - 1)
			: (ft_strlen(str)));
}

void	ft_prepend(char c, int nbr, int *written)
{
	int		i;

	i = 0;
	if (c == 'x')
		write(1, "0x", (nbr = 2));
	else if (c == 'X')
		write(1, "0X", (nbr = 2));
	else if (ft_tolower(c) == 'o')
		write(1, "0", (nbr = 1));
	else
		while (i++ < nbr)
			write(1, &c, 1);
	*written += nbr;
}

void	ft_padandprint(char **str, t_format **f, int *written)
{
	int		fldsize;
	char	sign;
	int		o;
	char	pad[2];

	printf("test \n");
	if (!*str || !*f || !written)
		return ;
	ft_strcpy(pad, "r ");
	o = ((*((*f)->type) == 'o' && (*f)->flags && (*f)->flags->hash) ? 1 : 0);
	fldsize = size(*str);
	if ((*f)->width && (*f)->width->max > fldsize)
		fldsize = (*f)->width->max;
	if ((*f)->width && (*f)->width->min > fldsize)
	{	if ((*f)->flags && ((*f)->flags->zero || (*f)->flags->minus))
			(((*f)->flags->minus) ? ft_strcpy(pad, "l ") : ft_strcpy(pad, "r0"));
		if (pad[0] == 'r')
		{
			ft_prepend(pad[1], (*f)->width->min - fldsize - o, written);
			printf("\npad with : [%c] minpad %d\n", pad[1], (*f)->width->min - fldsize);
		}
	}
	if (*(*str) == '-' || ((*f)->flags && ((*f)->flags->plus || (*f)->flags->space)))
	{
		((*(*str) == '-') ? (sign = '-') : 0);
		(((*f)->flags->plus) ? (sign = '+') : (sign = ' '));
		ft_prepend(sign, 1, written);
		fldsize++;
	}
	if ((*f)->flags && (*f)->flags->hash)
		(*((*f)->type) == 'o' && (o = 1)) ? ft_prepend(*((*f)->type), 1, written)
		: ft_prepend(*((*f)->type), 1, written);
	if (fldsize > size(*str) + o)
		ft_prepend('0', fldsize - size(*str) - o, written); 
	((*(*str) == '-') ? write(1, *str + 1, ft_strlen(*str)) :
	 write(1, *str, ft_strlen(*str)));//printwstr
	if ((*f)->width && (*f)->width->min > fldsize && pad[0] == 'l')
		ft_prepend(pad[1], (*f)->width->min - fldsize - o, written);
}
/*
int		main()
{
	int written = 0;
	char str = ' ';
	ft_prepend(str, 5, &written);
	printf("%d\n", written);
	//printf("%-4d\n", size(str));
	return (0);
}
*/
