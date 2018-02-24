/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dstrdel.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nfinkel <nfinkel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/24 23:13:04 by nfinkel           #+#    #+#             */
/*   Updated: 2018/02/24 23:15:22 by nfinkel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./dynstr.h"

void			ft_dstrdel(t_dstr *dstr, t_vdstor vdstor, ...)
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
			vdstor(dstr, cpy);
			va_end(cpy);
		}
		dstr->len = 0;
	}
	va_end(ap);
}
