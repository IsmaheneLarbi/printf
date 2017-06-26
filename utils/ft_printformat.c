/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printformat.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilarbi <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/08 18:58:49 by ilarbi            #+#    #+#             */
/*   Updated: 2017/06/24 19:41:09 by ilarbi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

void	ft_printformat(t_format *f)
{
	if (f->flags)
	{
		ft_printf("**************************flags****************************\n");
		ft_printf("plus  |  minus  | zero | space  | hash \n"); 
		ft_putnbr(f->flags->plus); ft_printf("  |  "); 
		ft_putnbr(f->flags->minus);ft_printf(" 	|  ");
		ft_putnbr(f->flags->zero);ft_printf(" 	|  ");
		ft_putnbr(f->flags->space);ft_printf(" 	|  ");
		ft_putnbr(f->flags->hash);
		ft_printf("\n");
	}
	if (f->width)
	{
		ft_printf("**************************width****************************\n");
		ft_printf("min  |  precsion  | max  \n"); 
		ft_putnbr(f->width->min);ft_printf("  |  ");
		ft_putnbr(f->width->precision);ft_printf("  |  ");
		ft_putnbr(f->width->max);
		ft_printf("\n");
	}
	if (f->len)
	{
		ft_printf("***************************len*****************************\n");
		ft_printf("h | hh | l | ll | j | z \n"); 
		ft_putnbr(f->len->h);ft_printf("  |  ");
		ft_putnbr(f->len->hh);ft_printf("  |  ");
		ft_putnbr(f->len->l);ft_printf("  |  ");
		ft_putnbr(f->len->ll);ft_printf("  |  ");
		ft_putnbr(f->len->j);ft_printf("  |  ");
		ft_putnbr(f->len->z);ft_printf("\n");
	}
	if (f->type)
	{
		ft_printf("************************type******************************\n");
		ft_putstr(f->type);
		ft_putchar('\n');
	}
}
