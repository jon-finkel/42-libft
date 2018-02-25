/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   del.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nfinkel <nfinkel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/25 17:21:09 by nfinkel           #+#    #+#             */
/*   Updated: 2018/02/25 22:20:09 by nfinkel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./vary.h"
#include "../mem/mem.h"
#include "../str/str.h"

void			ft_dstrdel(t_dstr **adstr)
{
	char		*str;

	if ((*adstr)->buff)
	{
		str = ft_dstrbegin(*adstr) - sizeof(char);
		while ((str += sizeof(char)) != ft_dstrend(*adstr))
			ft_strdel(&str);
		ft_strdel(&(*adstr)->buff);
	}
	*adstr = NULL;
}

void			ft_varydel(t_vary **avar, t_vdtor vdtor, ...)
{
	char		*ptr;
	va_list		ap;
	va_list		cpy;

	va_start(ap, vdtor);
	if ((*avar)->buff)
	{
		ptr = (char *)ft_varybegin(*avar) - (*avar)->data_size;
		while ((ptr += (*avar)->data_size) != ft_varyend(*avar))
		{
			va_copy(cpy, ap);
			vdtor(ptr, cpy);
			va_end(cpy);
		}
		ft_memdel(&(*avar)->buff);
	}
	*avar = NULL;
	va_end(ap);
}
