/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vec.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nfinkel <nfinkel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/19 15:29:04 by nfinkel           #+#    #+#             */
/*   Updated: 2018/03/22 16:26:39 by nfinkel          ###   ########.fr       */
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

t_vec4			*ft_vecrotx(t_vec4 *vec, double theta)
{
	double		tmp;

	tmp = (sin(theta) * vec->y) + (cos(theta) * vec->z);
	vec->y = (cos(theta) * vec->y) - (sin(theta) * vec->z);
	vec->z = tmp;
	GIMME(vec);
}

t_vec4			*ft_vecroty(t_vec4 *vec, double theta)
{
	double		tmp;

	tmp = -(sin(theta) * vec->x) + (cos(theta) * vec->z);
	vec->x = (cos(theta) * vec->x) + (sin(theta) * vec->z);
	vec->z = tmp;
	GIMME(vec);
}

t_vec4			*ft_vecrotz(t_vec4 *vec, double theta)
{
	double		tmp;

	tmp = (sin(theta) * vec->x) + (cos(theta) * vec->y);
	vec->x = (cos(theta) * vec->x) - (sin(theta) * vec->y);
	vec->y = tmp;
	GIMME(vec);
}
