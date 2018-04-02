/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   err.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nfinkel <nfinkel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/28 09:57:42 by nfinkel           #+#    #+#             */
/*   Updated: 2018/04/02 20:13:55 by nfinkel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/hdl.h"
#include "libft/io.h"

static const char		*g_errcode[ERRMAX] =
{
	"could not allocate memory",
	"could not open a valid file descriptor",
	"could not close file descriptor",
	"error while reading on file descriptor",
	"could not initialize mlx",
	"could not initialize mlx window",
	"could not initialize mlx image"
};

_Noreturn void			ft_errhdl(void **aptr, size_t size, int errcode)
{
	(void)aptr;
	if (errcode == ERR_READ)
		ft_dprintf(STDERR_FILENO, "fatal: %s %d\n", g_errcode[errcode], size);
	else if (errcode <= ERRMAX)
		ft_fatal(g_errcode[errcode], errcode);
	else
		ft_fatal("unknown error.", errcode);
	exit(errcode);
}
