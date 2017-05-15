/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilarbi <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/03 23:04:07 by ilarbi            #+#    #+#             */
/*   Updated: 2017/05/14 19:10:40 by ilarbi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "ft_printf.h"

int		main(void)
{
	char *format = "+- 10.20ld";
	t_format f = ft_memalloc(sizeof(t_format));
	//long d = 123456789012;
	//ft_putnbr(printf("%-010%%ld\n", d));   
	//ft_putnbr(printf("%10%%ld\n", d));   
	//ft_putnbr(printf("%010%%ld\n", d));   
	//ft_putnbr(printf("%-10%%ld\n", d));   
	//ft_putnbr(printf("% -+10.20ld\n", d));   
	//ft_putnbr(printf("% -+10.20l\n", d));   
	ft_checkforflags(&format, &f);
	ft_checkforwidth(&format, &f);
	ft_checkforlen(&format, &f);
	ft_printformat(f);
	return (0);
}
