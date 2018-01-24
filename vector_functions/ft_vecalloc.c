/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_vecalloc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nfinkel <nfinkel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/23 19:13:50 by nfinkel           #+#    #+#             */
/*   Updated: 2018/01/24 17:18:20 by nfinkel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./vector_private.h"
#include "../memory_functions/memory_private.h"

inline void			ft_vecalloc(t_vector *vector, size_t size)
{
	if (vector->capacity == size)
		BYEZ;
	vector->buff = ft_realloc(vector->buff, size * vector->data_size);
	vector->capacity = size;
	if (vector->len > size)
		vector->len = size;
	ft_memset(vector->buff + (vector->len * vector->data_size), '\0',\
		(vector->capacity - vector->len) * vector->data_size);
}
