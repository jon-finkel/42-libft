/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_varyalloc.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nfinkel <nfinkel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/25 09:03:07 by nfinkel           #+#    #+#             */
/*   Updated: 2018/02/25 09:03:13 by nfinkel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./vary.h"
#include "../memory_functions/memory.h"

static void			*reall(void *ptr, size_t len, size_t zlen)
{
	void		*tmp;

	tmp = ft_memalloc(zlen);
	if (ptr)
	{
		ft_memmove(tmp, ptr, len);
		ft_memdel(&ptr);
	}
	GIMME(tmp);
}

size_t				ft_varyalloc(t_vary *vary, size_t size)
{
	if (vary->capacity != size)
	{
		vary->buff = reall(vary->buff,\
			vary->len * vary->data_size, size * vary->data_size);
		vary->capacity = size;
		if (vary->len > size)
			vary->len = size;
		ft_memset(vary->buff + (vary->len * vary->data_size), '\0',\
			(vary->capacity - vary->len) * vary->data_size);
	}
	GIMME(vary->capacity);
}
