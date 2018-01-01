/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_realloc.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nfinkel <nfinkel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/10 14:20:54 by nfinkel           #+#    #+#             */
/*   Updated: 2018/01/01 16:16:32 by nfinkel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

void			*ft_realloc(void *ptr, size_t size)
{
	size_t		len;
	void		*tmp;

	if (!ptr)
		PROTECT(ptr = ft_memalloc(sizeof(*ptr) * size), ptr);
	else
	{
		len = ft_strlen((char *)ptr);
		if (!size)
			PROTECT(tmp = ft_memalloc(1), ptr);
		else
		{
			PROTECT(tmp = ft_memalloc(sizeof(*ptr) * size), ptr);
			ft_memmove(tmp, ptr, len);
		}
		free(ptr);
		ptr = tmp;
	}
	return (ptr);
}
