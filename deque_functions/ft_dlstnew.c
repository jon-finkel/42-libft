/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dlstnew.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nfinkel <nfinkel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/03 14:23:29 by nfinkel           #+#    #+#             */
/*   Updated: 2018/02/16 15:48:07 by nfinkel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./deque.h"
#include "../memory_functions/memory.h"

t_dlist			*ft_dlstnew(const void *data, size_t data_size)
{
	t_dlist		*dlist;

	dlist = (t_dlist *)ft_memalloc(sizeof(t_dlist));
	if (data)
	{
		dlist->data = ft_wralloc(data_size);
		dlist->data = ft_memmove(dlist->data, data, data_size);
		dlist->data_size = data_size;
	}
	GIMME(dlist);
}
