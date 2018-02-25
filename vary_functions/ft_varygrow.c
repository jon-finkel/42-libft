/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_varygrow.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nfinkel <nfinkel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/25 09:11:27 by nfinkel           #+#    #+#             */
/*   Updated: 2018/02/25 09:12:08 by nfinkel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./vary.h"
#include "../math_functions/math.h"

size_t			ft_varygrow(t_vary *vary, size_t size)
{
	if ((size += vary->len + 1) < VARY_MIN_SIZE
		&& VARY_MIN_SIZE > vary->capacity)
		GIMME(ft_varyalloc(vary, VARY_MIN_SIZE));
	else if (size > vary->capacity)
		GIMME(ft_varyalloc(vary, IS_POW2(size) ? size : ft_nextpower2(size)));
	GIMME(vary->capacity);
}
