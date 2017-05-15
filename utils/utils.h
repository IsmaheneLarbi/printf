/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilarbi <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/14 19:50:34 by ilarbi            #+#    #+#             */
/*   Updated: 2017/05/14 22:44:25 by ilarbi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef UTILS_H
# define UTILS_H
# include <stdlib.h>
# include "../libft/libft.h"

typedef struct s_flags              t_flags;
typedef struct s_width              t_width;
typedef struct s_length_modifiers   t_len;
typedef struct s_format             t_format;

int		ft_isflag(char c);
int		ft_iswidth(char c);
int		ft_islen(char c);
int		ft_istype(char c);
void	ft_checkforflags(const char **format, t_format **f);
void	ft_checkforwidth(const char **format, t_format **f);
void	ft_checkforlen(const char **format, t_format **f);
void	ft_printformat(t_format *f);

struct          s_flags
{
	int         hash;
	int         plus;
	int         minus;
	int         zero;
	int         space;
};

struct          s_width
{
	int         min;
	int         precision;
	int         max;
};

struct          s_length_modifiers
{
	int         hh;
	int         h;
	int         l;
	int         ll;
	int         j;
	int         z;
};

struct          s_format
{
	t_flags     *flags;
	t_width     *width;
	t_len       *len;
	char        *type;
};

#endif
