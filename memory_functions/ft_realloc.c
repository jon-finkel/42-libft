/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_realloc.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nfinkel <nfinkel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/10 14:20:54 by nfinkel           #+#    #+#             */
/*   Updated: 2017/12/12 22:58:59 by nfinkel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

void			*ft_realloc(void *ptr, size_t size)
{
	void		*tmp;

	if (!ptr)
		PROTECT(ptr = ft_memalloc(sizeof(ptr) * size), ptr);
	else if (!size && ptr)
	{
		PROTECT(tmp = ft_memalloc(1), ptr);
		free(ptr);
		ptr = tmp;
	}
	else if (size > ft_strlen((char *)ptr))
	{
		PROTECT(tmp = ft_memalloc(sizeof(ptr) * size), ptr);
		ft_memmove(tmp, ptr, size);
		free(ptr);
		ptr = tmp;
	}
	return (ptr);
}
