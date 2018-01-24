/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_vecgrow.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nfinkel <nfinkel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/23 19:08:39 by nfinkel           #+#    #+#             */
/*   Updated: 2018/01/24 17:27:01 by nfinkel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./vector_private.h"
#include "../math_functions/math_private.h"

inline size_t			ft_vecgrow(t_vector *vector, size_t size)
{
	if (vector->len + size > vector->capacity)
	{
		if (vector->capacity < VEC_MIN_LIMIT)
			ft_vecalloc(vector, VEC_MIN_LIMIT);
		else
			ft_vecalloc(vector, (IS_POW2(size) ? size : ft_nextpower2(size)));
	}
	GIMME(vector->capacity);
}
