/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   grow.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nfinkel <nfinkel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/25 17:21:20 by nfinkel           #+#    #+#             */
/*   Updated: 2018/03/11 23:19:01 by nfinkel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./vary.h"
#include "../math/mat.h"

size_t			ft_dstrgrow(t_dstr *dstr, size_t size)
{
	if ((size += dstr->len + 1) < DSTR_MIN_SIZE
		&& DSTR_MIN_SIZE > dstr->capacity)
		GIMME(ft_dstralloc(dstr, DSTR_MIN_SIZE));
	else if (size > dstr->capacity)
		GIMME(ft_dstralloc(dstr, IS_POW2(size) ? size : ft_nextpower2(size)));
	GIMME(dstr->capacity);
}

size_t			ft_varygrow(t_vary *vary, size_t size)
{
	if ((size += vary->len + 1) < VARY_MIN_SIZE
		&& VARY_MIN_SIZE > vary->capacity)
		GIMME(ft_varyalloc(vary, VARY_MIN_SIZE));
	else if (size > vary->capacity)
		GIMME(ft_varyalloc(vary, IS_POW2(size) ? size : ft_nextpower2(size)));
	GIMME(vary->capacity);
}
