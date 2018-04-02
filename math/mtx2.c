/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mtx2.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nfinkel <nfinkel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/02 17:39:25 by nfinkel           #+#    #+#             */
/*   Updated: 2018/04/02 17:39:26 by nfinkel          ###   ########.fr       */
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

t_vec4			**ft_veciter(t_vec4 **avec, const t_m4 matrix, size_t size)
{
	int		k;

	k = -1;
	while ((size_t)++k < size)
		ft_v4_m4(avec[k], matrix);
	GIMME(avec);
}

t_vec4			*ft_vecmap(t_vec4 *vec, double x, double y, double z)
{
	vec->x = x;
	vec->y = y;
	vec->z = z;
	GIMME(vec);
}

t_vec4			*ft_v4_m4(t_vec4 *vec, const t_m4 matrix)
{
	t_vec4		tmp;

	tmp.x = (matrix.a[0] * vec->x) + (matrix.a[1] * vec->y);
	tmp.x += (matrix.a[2] * vec->z) + (matrix.a[3] * (vec->w ? 1.0 : 0.0));
	tmp.y = (matrix.b[0] * vec->x) + (matrix.b[1] * vec->y);
	tmp.y += (matrix.b[2] * vec->z) + (matrix.b[3] * (vec->w ? 1.0 : 0.0));
	tmp.z = (matrix.c[0] * vec->x) + (matrix.c[1] * vec->y);
	tmp.z += (matrix.c[2] * vec->z) + (matrix.c[3] * (vec->w ? 1.0 : 0.0));
	tmp.w = (matrix.d[0] * vec->x) + (matrix.d[1] * vec->y);
	tmp.w += (matrix.d[2] * vec->z) + (matrix.d[3] * (vec->w ? 1.0 : 0.0));
	ft_memmove(vec, &tmp, sizeof(t_vec4));
	GIMME(vec);
}

t_m4			ft_m4_m4(const t_m4 m1, const t_m4 m2)
{
	t_m4		m;
	t_vec4		*vec;

	vec = ft_v4_m4(ft_vecnew(m2.a[0], m2.b[0], m2.c[0], m2.d[0]), m1);
	m.a[0] = vec->x;
	m.b[0] = vec->y;
	m.c[0] = vec->z;
	m.d[0] = vec->w;
	ft_v4_m4(ft_vecmap(vec, m2.a[1], m2.b[1], m2.c[1]), m1);
	m.a[1] = vec->x;
	m.b[1] = vec->y;
	m.c[1] = vec->z;
	m.d[1] = vec->w;
	ft_v4_m4(ft_vecmap(vec, m2.a[2], m2.b[2], m2.c[2]), m1);
	m.a[2] = vec->x;
	m.b[2] = vec->y;
	m.c[2] = vec->z;
	m.d[2] = vec->w;
	ft_v4_m4(ft_vecmap(vec, m2.a[3], m2.b[3], m2.c[3]), m1);
	m.a[3] = vec->x;
	m.b[3] = vec->y;
	m.c[3] = vec->z;
	m.d[3] = vec->w;
	ft_memdel((void **)&vec);
	GIMME(m);
}
