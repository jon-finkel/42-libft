/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   err.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nfinkel <nfinkel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/28 09:57:42 by nfinkel           #+#    #+#             */
/*   Updated: 2018/03/03 22:23:02 by nfinkel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../io/io.h"
#include "../includes/handlers.h"

_Noreturn void			ft_errhdl(void **aptr, size_t size, int errcode)
{
	(void)aptr;
	(void)size;
	(void)errcode;
	if (errcode == ENOMEM)
		ft_fatal("could not allocate memory.");
	else if (errcode == EINVAL)
		ft_fatal("read failed.");
	else if (errcode == EIO)
		ft_fatal("could not open file.");
	else
		ft_fatal("unknown error.");
}
