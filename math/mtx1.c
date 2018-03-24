/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   matrix.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nfinkel <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/23 19:05:44 by nfinkel           #+#    #+#             */
/*   Updated: 2018/03/24 16:52:02 by nfinkel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/mat.h"
#include "libft/mem.h"

t_m4			*ft_m4rotx(t_m4 *matrix, double theta)
{
	double		c;
	double		s;

	c = cos(theta);
	s = sin(theta);
	ft_memset(matrix, '\0', sizeof(t_m4));
	matrix->a = 1;
	matrix->f = c;
	matrix->g = (s ? -s : 0);
	matrix->j = s;
	matrix->k = c;
	matrix->p = true;
	GIMME(matrix);
}

t_m4			*ft_m4roty(t_m4 *matrix, double theta)
{
	double		c;
	double		s;

	c = cos(theta);
	s = sin(theta);
	ft_memset(matrix, '\0', sizeof(t_m4));
	matrix->a = c;
	matrix->c = s;
	matrix->f = 1;
	matrix->i = (s ? -s : 0);
	matrix->k = c;
	matrix->p = true;
	GIMME(matrix);
}

t_m4			*ft_m4rotz(t_m4 *matrix, double theta)
{
	double		c;
	double		s;

	c = cos(theta);
	s = sin(theta);
	ft_memset(matrix, '\0', sizeof(t_m4));
	matrix->a = c;
	matrix->b = (s ? -s : 0);
	matrix->e = s;
	matrix->f = c;
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
