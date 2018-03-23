/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mtx2.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nfinkel <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/23 19:38:36 by nfinkel           #+#    #+#             */
/*   Updated: 2018/03/23 23:13:23 by nfinkel          ###   ########.fr       */
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
	t_vec4		tmp;

	tmp.x = (vec->x * matrix.a) + (vec->y * matrix.b) + (vec->z * matrix.c);
	tmp.x += (vec->w * matrix.d);
	tmp.y = (vec->x * matrix.e) + (vec->y * matrix.f) + (vec->z * matrix.g);
	tmp.y += (vec->w * matrix.h);
	tmp.z = (vec->x * matrix.i) + (vec->y * matrix.j) + (vec->z * matrix.k);
	tmp.z += (vec->w * matrix.l);
	tmp.w = (vec->x * matrix.m) + (vec->y * matrix.n) + (vec->z * matrix.o);
	tmp.w += (vec->w * matrix.p);
	ft_memmove(vec, &tmp, sizeof(t_vec4));
	GIMME(vec);
}

t_m4			*ft_m4_m4(t_m4 *m1, const t_m4 *m2)
{
	t_m4		tmp;

	tmp.a = m1->a * m2->a + m1->b * m2->e + m1->c * m2->i + m1->d * m2->m;
	tmp.b = m1->a * m2->b + m1->b * m2->f + m1->c * m2->j + m1->d * m2->n;
	tmp.c = m1->a * m2->c + m1->b * m2->g + m1->c * m2->k + m1->d * m2->o;
	tmp.d = m1->a * m2->d + m1->b * m2->h + m1->c * m2->l + m1->d * m2->p;
	tmp.e = m1->e * m2->a + m1->f * m2->e + m1->g * m2->i + m1->h * m2->m;
	tmp.f = m1->e * m2->b + m1->f * m2->f + m1->g * m2->j + m1->h * m2->n;
	tmp.g = m1->e * m2->c + m1->f * m2->g + m1->g * m2->k + m1->h * m2->o;
	tmp.h = m1->e * m2->d + m1->f * m2->h + m1->g * m2->i + m1->h * m2->p;
	tmp.i = m1->i * m2->a + m1->j * m2->e + m1->k * m2->i + m1->l * m2->m;
	tmp.j = m1->i * m2->b + m1->j * m2->f + m1->k * m2->j + m1->l * m2->n;
	tmp.k = m1->i * m2->c + m1->j * m2->g + m1->k * m2->k + m1->l * m2->o;
	tmp.l = m1->i * m2->d + m1->j * m2->h + m1->k * m2->l + m1->l * m2->p;
	tmp.m = m1->m * m2->a + m1->n * m2->e + m1->o * m2->i + m1->p * m2->m;
	tmp.n = m1->m * m2->b + m1->n * m2->f + m1->o * m2->j + m1->p * m2->n;
	tmp.o = m1->m * m2->c + m1->n * m2->g + m1->o * m2->k + m1->p * m2->o;
	tmp.p = m1->m * m2->d + m1->n * m2->h + m1->o * m2->l + m1->p * m2->p;
	ft_memmove(m1, &tmp, sizeof(t_m4));
	GIMME(m1);
}
