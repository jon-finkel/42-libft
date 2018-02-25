/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_varydel.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nfinkel <nfinkel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/25 09:09:38 by nfinkel           #+#    #+#             */
/*   Updated: 2018/02/25 09:09:39 by nfinkel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./vary.h"
#include "../memory_functions/memory.h"

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
