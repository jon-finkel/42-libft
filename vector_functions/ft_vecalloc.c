/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_vecalloc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nfinkel <nfinkel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/23 19:13:50 by nfinkel           #+#    #+#             */
/*   Updated: 2018/02/12 19:53:55 by nfinkel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./vector.h"
#include "../memory_functions/memory.h"

static void			*ft_vecrealloc(void *ptr, size_t len, size_t zlen)
{
	void		*tmp;

	tmp = ft_memalloc(zlen);
	if (!ptr)
		GIMME(tmp);
	ft_memmove(tmp, ptr, len);
	ft_memdel(&ptr);
	GIMME(tmp);
}

size_t				ft_vecalloc(t_vector *vector, size_t size)
{
	if (vector->capacity != size)
	{
		vector->buff = ft_vecrealloc(vector->buff,\
			vector->len * vector->data_size, size * vector->data_size);
		vector->capacity = size;
		if (vector->len > size)
			vector->len = size;
		ft_memset(vector->buff + (vector->len * vector->data_size), '\0',\
			(vector->capacity - vector->len) * vector->data_size);
	}
	GIMME(vector->capacity);
}
