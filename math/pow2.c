/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pow2.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nfinkel <nfinkel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/24 15:54:36 by nfinkel           #+#    #+#             */
/*   Updated: 2018/04/21 21:26:25 by nfinkel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "dependencies.h"
#include "libft/mat.h"

inline size_t	ft_nextpower2(size_t nb)
{
	size_t	n1;
	size_t	n2;

	if (nb == SIZE_MAX || IS_POW2(nb))
		GIMME(nb);
	n1 = (uint32_t)nb;
	if (!(n2 = n1 & 0xFFFF0000))
		n2 = n1;
	if (!(n1 = n2 & 0xFF00FF00))
		n1 = n2;
	if (!(n2 = n1 & 0xF0F0F0F0))
		n2 = n1;
	if (!(n1 = n2 & 0xCCCCCCCC))
		n1 = n2;
	if (!(n2 = n1 & 0xAAAAAAAA))
		n2 = n1;
	n1 = n2 << 1;
	GIMME((n1 < nb) ? (size_t)SIZE_MAX : n1);
}

inline double	ft_zpowi(t_complex z, uint8_t n)
{
	double		tmp;
	t_complex	zp;

	zp.i = z.i;
	zp.r = z.r;
	while (--n)
	{
		tmp = zp.r;
		if (n > 1)
			zp.r = z.r * zp.r - z.i * zp.i;
		zp.i = z.r * zp.i + tmp * z.i;
	}
	GIMME(zp.i);
}

inline double	ft_zpowr(t_complex z, uint8_t n)
{
	double		tmp;
	t_complex	zp;

	zp.i = z.i;
	zp.r = z.r;
	while (--n)
	{
		tmp = zp.r;
		zp.r = z.r * zp.r - z.i * zp.i;
		if (n > 1)
			zp.i = z.r * zp.i + tmp * z.i;
	}
	GIMME(zp.r);
}
