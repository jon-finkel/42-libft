/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_vecclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nfinkel <nfinkel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/29 06:27:00 by nfinkel           #+#    #+#             */
/*   Updated: 2018/02/24 23:00:17 by nfinkel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./vector.h"
#include "../memory_functions/memory.h"

void			ft_vecclear(t_vector *vector, t_vdtor vdtor, ...)
{
	char		*ptr;
	va_list		ap;
	va_list		cpy;

	va_start(ap, vdtor);
	if (vector->buff)
	{
		ptr = (char *)ft_vecbegin(vector) - vector->data_size;
		while ((ptr += vector->data_size) != ft_vecend(vector))
		{
			va_copy(cpy, ap);
			vdtor(ptr, cpy);
			va_end(cpy);
		}
		ft_memdel(&vector->buff);
	}
	va_end(ap);
	ft_memset(vector, '\0', sizeof(t_vector));
}
