/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   alloc.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nfinkel <nfinkel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/25 17:20:44 by nfinkel           #+#    #+#             */
/*   Updated: 2018/02/25 22:19:54 by nfinkel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./vary.h"
#include "../mem/mem.h"

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

size_t				ft_dstralloc(t_dstr *dstr, size_t size)
{
	if (dstr->capacity != size)
	{
		dstr->buff = (char *)reall(dstr->buff, dstr->len, size * sizeof(char));
		if (dstr->len > (dstr->capacity = size))
			dstr->len = size;
		ft_memset(dstr->buff + dstr->len, '\0', dstr->capacity - dstr->len);
	}
	GIMME(dstr->capacity);
}

size_t				ft_varyalloc(t_vary *vary, size_t size)
{
	if (vary->capacity != size)
	{
		vary->buff = reall(vary->buff,\
			vary->len * vary->data_size, size * vary->data_size);
		if (vary->len > (vary->capacity = size))
			vary->len = size;
		ft_memset(vary->buff + (vary->len * vary->data_size), '\0',\
			(vary->capacity - vary->len) * vary->data_size);
	}
	GIMME(vary->capacity);
}
