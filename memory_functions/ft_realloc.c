/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_realloc.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nfinkel <nfinkel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/10 14:20:54 by nfinkel           #+#    #+#             */
/*   Updated: 2018/02/12 20:23:17 by nfinkel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./memory.h"
#include "../string_functions/string.h"

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
