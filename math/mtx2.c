/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mtx2.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nfinkel <nfinkel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/02 17:39:25 by nfinkel           #+#    #+#             */
/*   Updated: 2018/04/05 15:43:58 by nfinkel          ###   ########.fr       */
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

void			ft_veciter(t_vec4 **avec, const t_m4 matrix, size_t size)
{
	int		k;

	k = -1;
	while ((size_t)++k < size)
		ft_v4_m4(avec[k], matrix);
}

t_vec4			*ft_vecmap(t_vec4 *vec, double x, double y, double z)
{
	vec->x = x;
	vec->y = y;
	vec->z = z;
	GIMME(vec);
}

void			ft_veccenter(t_vec4 **avec, size_t size, const t_p2 pos)
{
	double		new_x;
	double		new_y;
	size_t		k;

	new_x = pos.x - (size % 2 ? avec[size / 2]->x
		: (avec[size / 2]->x + avec[size / 2 - 1]->x) / 2);
	new_y = pos.y - (size % 2 ? avec[size / 2]->y
		: (avec[size / 2]->y + avec[size / 2 - 1]->y) / 2);
	k = -1;
	while (++k < size)
	{
		avec[k]->x += new_x;
		avec[k]->y += new_y;
	}
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
