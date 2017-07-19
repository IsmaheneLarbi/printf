/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilarbi <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/07 17:54:33 by ilarbi            #+#    #+#             */
/*   Updated: 2017/07/18 12:53:48 by ilarbi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include <wchar.h>
# include <stdarg.h>
# include <unistd.h>
# include <stdlib.h>
# include <inttypes.h>
# include <limits.h>
# include "libft/libft.h"
# include "utils/utils.h"

t_format	*ft_parse(const char **format);
char		*ft_convert(const char **format, int *written, va_list ap);
void		ft_padandprint(char **str, t_format **f, int *written, int *size);
int			ft_printf(const char *format, ...);

#endif
