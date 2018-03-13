/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   err.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nfinkel <nfinkel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/28 09:57:42 by nfinkel           #+#    #+#             */
/*   Updated: 2018/03/14 00:39:29 by nfinkel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../io/io.h"
#include "../includes/handlers.h"

static const char		*g_error[] =
{
	"could not allocate memory",
	"wrong file descriptor"
};

_Noreturn void			ft_errhdl(void **aptr, size_t size, int errcode)
{
	(void)aptr;
	(void)size;
	(void)errcode;
	if (errcode <= ERR_MAX)
		ft_fatal(g_error[errcode]);
	else
		ft_fatal("unknown error.");
}
