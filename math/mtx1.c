/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mtx1.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nfinkel <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/23 19:05:44 by nfinkel           #+#    #+#             */
/*   Updated: 2018/03/29 20:02:54 by nfinkel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/mat.h"
#include "libft/mem.h"

t_m4			ft_m4rotx(double theta)
{
	double		c;
	double		s;
	t_m4		matrix;

	c = cos(theta);
	s = sin(theta);
	ft_memset(&matrix, '\0', sizeof(t_m4));
	matrix.a[1] = 1.0;
	matrix.b[1] = c;
	matrix.b[2] = -s;
	matrix.c[1] = s;
	matrix.c[2] = c;
	matrix.d[3] = true;
	GIMME(matrix);
}

t_m4			ft_m4roty(double theta)
{
	double		c;
	double		s;
	t_m4		matrix;

	c = cos(theta);
	s = sin(theta);
	ft_memset(&matrix, '\0', sizeof(t_m4));
	matrix.a[0] = c;
	matrix.a[2] = c;
	matrix.b[1] = 1.0;
	matrix.c[0] = -s;
	matrix.c[2] = c;
	matrix.d[3] = true;
	GIMME(matrix);
}

t_m4			ft_m4rotz(double theta)
{
	double		c;
	double		s;
	t_m4		matrix;

	c = cos(theta);
	s = sin(theta);
	ft_memset(&matrix, '\0', sizeof(t_m4));
	matrix.a[0] = c;
	matrix.a[1] = -s;
	matrix.b[0] = s;
	matrix.b[1] = c;
	matrix.c[2] = 1.0;
	matrix.d[3] = true;
	GIMME(matrix);
}

t_m4			ft_m4scale(double sx, double sy, double sz)
{
	t_m4		matrix;

	ft_memset(&matrix, '\0', sizeof(t_m4));
	matrix.a[0] = sx;
	matrix.b[1] = sy;
	matrix.c[2] = sz;
	matrix.d[3] = true;
	GIMME(matrix);
}

t_m4			ft_m4trans(double x, double y, double z)
{
	t_m4		matrix;

	ft_memset(&matrix, '\0', sizeof(t_m4));
	matrix.a[0] = 1.0;
	matrix.a[3] = x;
	matrix.b[1] = 1.0;
	matrix.b[3] = y;
	matrix.c[2] = 1.0;
	matrix.c[3] = z;
	matrix.d[3] = true;
	GIMME(matrix);
}
