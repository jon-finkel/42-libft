/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dstralloc.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nfinkel <nfinkel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/24 22:53:32 by nfinkel           #+#    #+#             */
/*   Updated: 2018/02/24 22:56:01 by nfinkel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./dynstr.h"
#include "../memory_functions/memory.h"

static void			*ft_dstrrealloc(char *ptr, size_t len, size_t zlen)
{
	void		*tmp;

	tmp = ft_memalloc(zlen);
	if (ptr)
	{
		ft_memmove(tmp, ptr, len);
		ft_memdel((void **)&ptr);
	}
	GIMME(tmp);
}

size_t				ft_dstralloc(t_dstr *dstr, size_t size)
{
	if (dstr->capacity != size)
	{
		dstr->buff = ft_dstrrealloc(dstr->buff, dstr->len, size);
		dstr->capacity = size;
		if (dstr->len > size)
			dstr->len = size;
		ft_memset(dstr->buff + dstr->len, '\0', dstr->capacity - dstr->len);
	}
	GIMME(dstr->capacity);
}
