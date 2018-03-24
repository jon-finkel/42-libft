/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put3.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nfinkel <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/24 21:02:41 by nfinkel           #+#    #+#             */
/*   Updated: 2018/03/24 21:18:47 by nfinkel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/mat.h"
#include "libft/io.h"

void			ft_putmatrix(const t_m4 *matrix)
{
	char		c1;
	char		c2;
	char		c3;
	char		c4;

	c1 = (matrix->m ? '1' : '0');
	c2 = (matrix->n ? '1' : '0');
	c3 = (matrix->o ? '1' : '0');
	c4 = (matrix->p ? '1' : '0');
	ft_printf("4x4 MATRIX (%p)\n[%9f, %9f, %9f, %9f]\n[%9f, %9f, %9f, %9f]\n"\
		"[%9f, %9f, %9f, %9f]\n[%9c, %9c, %9c, %9c]\n", matrix, matrix->a,\
		matrix->b, matrix->c, matrix->d, matrix->e, matrix->f, matrix->g,\
		matrix->h, matrix->i, matrix->j, matrix->k, matrix->l, c1, c2, c3, c4);
}

void			ft_putvector(const t_vec4 *vec)
{
	ft_printf("4x1 VECTOR (%p)\n[%9f]\n[%9f]\n[%9f]\n[%9c]\n", vec, vec->x,\
		vec->y, vec->z, vec->w ? '1' : '0');
}
