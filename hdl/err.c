/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   err.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nfinkel <nfinkel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/28 09:57:42 by nfinkel           #+#    #+#             */
/*   Updated: 2018/03/28 21:50:16 by nfinkel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/hdl.h"
#include "libft/io.h"

static const char		*g_errcode[ERRMAX] =
{
	"could not allocate memory",
	"could not open file",
	"could not initialize mlx",
	"could not initialize mlx window",
	"could not initialize mlx image"
};

_Noreturn void			ft_errhdl(void **aptr, size_t size, int errcode)
{
	(void)aptr;
	(void)size;
	if (errcode <= ERRMAX)
		ft_fatal(g_errcode[errcode]);
	else
		ft_fatal("unknown error.");
}
