/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_vecclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nfinkel <nfinkel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/29 06:27:00 by nfinkel           #+#    #+#             */
/*   Updated: 2018/02/12 20:55:19 by nfinkel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./vector.h"
#include "../memory_functions/memory.h"

void			ft_vecclear(t_vector *vector, t_vdtor del)
{
	char		*ptr;

	if (vector->buff)
	{
		if (del)
		{
			ptr = (char *)ft_vecbegin(vector) - vector->data_size;
			while ((ptr += vector->data_size) != ft_vecend(vector))
				del(ptr);
		}
		free(vector->buff);
	}
	ft_memset(vector, '\0', sizeof(t_vector));
}
