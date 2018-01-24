/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_vecgrow.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nfinkel <nfinkel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/23 19:08:39 by nfinkel           #+#    #+#             */
/*   Updated: 2018/01/24 16:51:34 by nfinkel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./vector_private.h"
#include "../math_functions/math_private.h"

inline size_t			ft_vecgrow(t_vector *vector, size_t len)
{
	if ((len += vector->len + 1) < VEC_MIN_LIMIT
		&& VEC_MIN_LIMIT > vector->limit)
		GIMME(ft_vecalloc(vector, VEC_MIN_LIMIT));
	else if (len > vector->limit)
		GIMME(ft_vecalloc(vector, IS_POW2(len) ? len : ft_nextpower2(len)));
	GIMME(vector->limit);
}
