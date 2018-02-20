/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_vecdel.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nfinkel <nfinkel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/29 06:27:15 by nfinkel           #+#    #+#             */
/*   Updated: 2018/02/20 09:46:08 by nfinkel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./vector.h"

void			ft_vecvdtor(t_vector *vector, t_vdtor vdtor, ...)
{
	char		*ptr;
	va_list		ap;
	va_list		cpy;

	va_start(ap, vdtor);
	if (vector->buff && vdtor)
	{
		ptr = (char *)ft_vecbegin(vector) - vector->data_size;
		while ((ptr += vector->data_size) != (char *)ft_vecend(vector))
		{
			va_copy(cpy, ap);
			vdtor(ptr, ap);
			va_end(cpy);
		}
		vector->len = 0;
	}
	va_end(ap);
}
