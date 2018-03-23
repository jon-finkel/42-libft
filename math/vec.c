/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vec.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nfinkel <nfinkel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/19 15:29:04 by nfinkel           #+#    #+#             */
/*   Updated: 2018/03/23 19:24:15 by nfinkel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/mat.h"
#include "libft/mem.h"

t_vec4			*ft_vecnew(double x, double y, double z, bool w)
{
	t_vec4		*vec;

	vec = (t_vec4 *)ft_wralloc(sizeof(t_vec4));
	vec->x = x;
	vec->y = y;
	vec->z = z;
	vec->w = w;
	GIMME(vec);
}

t_vec4			*ft_v4_m4(t_vec4 *vec, const t_m4 matrix)
{
	double		x;
	double		y;
	double		z;
	double		w;

	x = vec->x * matrix.a[0] + vec->y * matrix.a[1] + vec->z * matrix.a[2];
	x += (vec->w ? 1.0 : 0.0) * (matrix.a[3] ? 1.0 : 0.0);
	y = vec->x * matrix.b[0] + vec->y * matrix.b[1] + vec->z * matrix.b[2];
	y += (vec->w ? 1.0 : 0.0) * (matrix.b[3] ? 1.0 : 0.0);
	z = vec->x * matrix.c[0] + vec->y * matrix.c[1] + vec->z * matrix.c[2];
	z += (vec->w ? 1.0 : 0.0) * (matrix.c[3] ? 1.0 : 0.0);
	w = vec->x * matrix.d[0] + vec->y * matrix.d[1] + vec->z * matrix.d[2];
	w += (vec->w ? 1.0 : 0.0) * (matrix.d[3] ? 1.0 : 0.0);
	vec->x = x;
	vec->y = y;
	vec->z = z;
	vec->w = (w ? true : false);
	GIMME(vec);
}
