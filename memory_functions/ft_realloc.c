/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_realloc.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nfinkel <nfinkel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/10 14:20:54 by nfinkel           #+#    #+#             */
/*   Updated: 2018/01/23 19:52:16 by nfinkel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./memory_private.h"
#include "../string_functions/string_private.h"

inline void			*ft_realloc(void *ptr, size_t size)
{
	size_t		len;
	void		*tmp;

	if (!ptr)
		FAILZ(ptr = ft_memalloc(sizeof(*ptr) * size), ptr);
	else
	{
		len = ft_strlen((char *)ptr);
		if (!size)
			FAILZ(tmp = ft_memalloc(1), ptr);
		else
		{
			FAILZ(tmp = ft_memalloc(sizeof(*ptr) * size), ptr);
			ft_memmove(tmp, ptr, len);
		}
		free(ptr);
		ptr = tmp;
	}
	GIMME(ptr);
}
