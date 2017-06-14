/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_padmin_flags.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilarbi <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/14 14:10:11 by ilarbi            #+#    #+#             */
/*   Updated: 2017/06/14 15:18:24 by ilarbi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

void	addprefix(char type, char **result)
{
	if (ft_tolower(type) == 'o')
		ft_strjoin_free("0", 0, *result, 1);
	else if (ft_tolower(type) == 'x')
		((type = 'x') ? ft_strjoin_free("0x", 0, *result, 1) :
		 ft_strjoin_free("0X", 0, *result, 1));
	else
		exit(-1);	
}
/*
void	ft_padmin_flags(char **result, int pos, char type, char flag)
{
	if ((ft_tolower(type) == 'o' || ft_tolower(type) == 'x'))
		addprefix(type, result);
}
*/
int		main(int argc, char **argv)
{
	if (argc == 2)
		addprefix('o', &argv[1]);
	return (0);
}
