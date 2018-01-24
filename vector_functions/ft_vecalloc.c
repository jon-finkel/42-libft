/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_vecalloc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nfinkel <nfinkel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/23 19:13:50 by nfinkel           #+#    #+#             */
/*   Updated: 2018/01/24 15:48:28 by nfinkel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./vector_private.h"
#include "../memory_functions/memory_private.h"

inline size_t			ft_vecalloc(t_vector *vector, size_t len)
{
	if (vector->limit != len)
	{
		vector->buff = ft_realloc(vector->buff, len * vector->size);
		vector->limit = len;
		if (vector->len > vector->limit)
			vector->len = len;
		ft_memset(vector->buff + (vector->len * vector->size), '\0',\
			(vector->limit - vector->len) * vector->size);
	}
	return (vector->limit);
}
