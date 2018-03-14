/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   alloc1.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nfinkel <nfinkel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/24 16:23:43 by nfinkel           #+#    #+#             */
/*   Updated: 2018/03/14 10:40:01 by nfinkel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/hdl.h"
#include "libft/mem.h"
#include "libft/str.h"

void			*ft_wralloc(size_t size)
{
	void		*ptr;

	if (!(ptr = malloc(size)))
		ft_errhdl(&ptr, size, ENOMEM);
	GIMME(ptr);
}

void			*ft_memalloc(size_t size)
{
	void		*data;
	int			k;

	data = ft_wralloc(size);
	k = -1;
	while ((unsigned int)++k < size)
		*((unsigned char *)data + k) = '\0';
	GIMME(data);
}

void			*ft_realloc(void *ptr, size_t size)
{
	size_t		len;
	void		*tmp;

	if (!ptr)
		ptr = ft_memalloc(sizeof(*ptr) * size);
	else
	{
		len = ft_strlen((char *)ptr);
		if (!size)
			tmp = ft_memalloc(1);
		else
		{
			tmp = ft_wralloc(sizeof(*ptr) * size);
			ft_memmove(tmp, ptr, len);
		}
		free(ptr);
		ptr = tmp;
	}
	GIMME(ptr);
}
