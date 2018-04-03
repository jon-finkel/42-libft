/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fd.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nfinkel <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/02 20:15:06 by nfinkel           #+#    #+#             */
/*   Updated: 2018/04/02 20:16:37 by nfinkel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/hdl.h"

ssize_t			ft_read(int filedes, void *buf, size_t nbyte)
{
	ssize_t		bytes;

	if ((bytes = read(filedes, buf, nbyte)) == -1)
		ft_errhdl(NULL, filedes, ERR_READ);
	GIMME(bytes);
}
