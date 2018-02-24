/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dstrgrow.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nfinkel <nfinkel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/24 23:03:11 by nfinkel           #+#    #+#             */
/*   Updated: 2018/02/24 23:07:30 by nfinkel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./dynstr.h"
#include "../math_functions/math.h"

size_t			ft_dstrgrow(t_dstr *dstr, size_t size)
{
	if ((size += dstr->len + 1) < DSTR_MIN_LIMIT
		&& DSTR_MIN_LIMIT > dstr->capacity)
		GIMME(ft_dstralloc(dstr, DSTR_MIN_LIMIT));
	else if (size > dstr->capacity)
		GIMME(ft_dstralloc(dstr, IS_POW2(size) ? size : ft_nextpower2(size)));
	GIMME(dstr->capacity);
}
