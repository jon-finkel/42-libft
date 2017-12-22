/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_realloc.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nfinkel <nfinkel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/10 14:20:54 by nfinkel           #+#    #+#             */
/*   Updated: 2017/12/22 23:29:13 by nfinkel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

void			*ft_realloc(void *ptr, size_t size)
{
	size_t		len;
	void		*tmp;

	if (ptr)
		len = ft_strlen((char *)ptr);
	if (!ptr)
		PROTECT(ptr = ft_memalloc(sizeof(*ptr) * size), ptr);
	else if (!size)
	{
		PROTECT(tmp = ft_memalloc(1), ptr);
		free(ptr);
		ptr = tmp;
	}
	else if (size > len)
	{
		PROTECT(tmp = ft_memalloc(sizeof(*ptr) * size), ptr);
		ft_memmove(tmp, ptr, len);
		free(ptr);
		ptr = tmp;
	}
	return (ptr);
}
