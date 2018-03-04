/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   err.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nfinkel <nfinkel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/28 09:57:42 by nfinkel           #+#    #+#             */
/*   Updated: 2018/03/04 17:50:25 by nfinkel          ###   ########.fr       */
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
	else
		ft_fatal("unknown error.");
}
