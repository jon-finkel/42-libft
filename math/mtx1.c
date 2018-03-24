/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   matrix.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nfinkel <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/23 19:05:44 by nfinkel           #+#    #+#             */
/*   Updated: 2018/03/24 16:03:33 by nfinkel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/mat.h"
#include "libft/mem.h"

t_m4			*ft_m4rotx(t_m4 *matrix, double theta)
{
	ft_memset(matrix, '\0', sizeof(t_m4));
	matrix->a = 1;
	matrix->f = cos(theta);
	matrix->g = 0 - sin(theta);
	matrix->j = sin(theta);
	matrix->k = cos(theta);
	matrix->p = true;
	GIMME(matrix);
}

t_m4			*ft_m4roty(t_m4 *matrix, double theta)
{
	ft_memset(matrix, '\0', sizeof(t_m4));
	matrix->a = cos(theta);
	matrix->c = sin(theta);
	matrix->f = 1;
	matrix->i = 0 - sin(theta);
	matrix->k = cos(theta);
	matrix->p = true;
	GIMME(matrix);
}

t_m4			*ft_m4rotz(t_m4 *matrix, double theta)
{
	ft_memset(matrix, '\0', sizeof(t_m4));
	matrix->a = cos(theta);
	matrix->b = 0 - sin(theta);
	matrix->e = sin(theta);
	matrix->f = cos(theta);
	matrix->k = 1;
	matrix->p = true;
	GIMME(matrix);
}

t_m4			*ft_m4scale(t_m4 *matrix, double sx, double sy, double sz)
{
	ft_memset(matrix, '\0', sizeof(t_m4));
	matrix->a = sx;
	matrix->f = sy;
	matrix->k = sz;
	matrix->p = true;
	GIMME(matrix);
}

t_m4			*ft_m4trans(t_m4 *matrix, double x, double y, double z)
{
	ft_memset(matrix, '\0', sizeof(t_m4));
	matrix->a = 1;
	matrix->d = x;
	matrix->f = 1;
	matrix->h = y;
	matrix->k = 1;
	matrix->l = z;
	matrix->p = true;
	GIMME(matrix);
}
