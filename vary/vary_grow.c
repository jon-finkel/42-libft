/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   grow.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nfinkel <nfinkel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/25 17:21:20 by nfinkel           #+#    #+#             */
/*   Updated: 2019/03/11 21:51:44 by nfinkel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/mat.h"
#include "libft/vary.h"

inline size_t	ft_dstrgrow(t_dstr *dstr, size_t size)
{
	if ((size += dstr->len + 1) < DSTR_MIN_SIZE
		&& DSTR_MIN_SIZE > dstr->capacity)
		return (ft_dstrctor(dstr, DSTR_MIN_SIZE));
	else if (size > dstr->capacity)
		return (ft_dstrctor(dstr, IS_POW2(size) ? size : ft_stnxpow2(size)));
	return (dstr->capacity);
}

inline size_t	ft_varygrow(t_vary *vary, size_t size)
{
	if ((size += vary->len + 1) < VARY_MIN_SIZE
		&& VARY_MIN_SIZE > vary->capacity)
		return (ft_varyctor(vary, VARY_MIN_SIZE));
	else if (size > vary->capacity)
		return (ft_varyctor(vary, IS_POW2(size) ? size : ft_stnxpow2(size)));
	return (vary->capacity);
}
