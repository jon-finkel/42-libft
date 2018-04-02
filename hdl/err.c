/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   err.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nfinkel <nfinkel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/28 09:57:42 by nfinkel           #+#    #+#             */
/*   Updated: 2018/04/02 18:50:37 by nfinkel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/hdl.h"
#include "libft/io.h"

static const char		*g_errcode[ERRMAX] =
{
	"could not allocate memory",
	"could not open a valid file descriptor",
	"could not close file descriptor",
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
