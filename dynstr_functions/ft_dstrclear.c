/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dstrclear.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nfinkel <nfinkel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/24 22:57:21 by nfinkel           #+#    #+#             */
/*   Updated: 2018/02/24 23:00:54 by nfinkel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./dynstr.h"
#include "../memory_functions/memory.h"

void			ft_dstrclear(t_dstr *dstr, t_vdstor vdstor, ...)
{
	char		*ptr;
	va_list		ap;
	va_list		cpy;

	va_start(ap, vdstor);
	if (dstr->buff)
	{
		ptr = ft_dstrbegin(dstr) - sizeof(char);
		while ((ptr += sizeof(char)) != ft_dstrend(dstr))
		{
			va_copy(cpy, ap);
			vdstor(ptr, cpy);
			va_end(cpy);
		}
		ft_memdel((void **)&dstr->buff);
	}
	va_end(ap);
	ft_memset(dstr, '\0', sizeof(t_dstr));
}
