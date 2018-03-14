/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   err.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nfinkel <nfinkel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/28 09:57:42 by nfinkel           #+#    #+#             */
/*   Updated: 2018/03/14 10:31:48 by nfinkel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/hdl.h"
#include "libft/io.h"

static const char		*g_errcode[ERRMAX] =
{
	"could not allocate memory",
	"could not open file"
};

_Noreturn void			ft_errhdl(void **aptr, size_t size, int errcode)
{
	(void)aptr;
	(void)size;
	(void)errcode;
	if (errcode <= ERRMAX)
		ft_fatal(g_errcode[errcode - 1]);
	else
		ft_fatal("unknown error.");
}
