/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   matrix.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nfinkel <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/23 19:05:44 by nfinkel           #+#    #+#             */
/*   Updated: 2018/03/23 19:18:17 by nfinkel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/mat.h"
#include "libft/mem.h"

t_m4			*ft_m4rotx(t_m4 *matrix, double theta)
{
	ft_memset(matrix, '\0', sizeof(t_m4));
	matrix->a[0] = 1;
	matrix->b[1] = cos(theta);
	matrix->b[2] = -sin(theta);
	matrix->c[1] = sin(theta);
	matrix->c[2] = cos(theta);
	matrix->d[3] = true;
	GIMME(matrix);
}

t_m4			*ft_m4roty(t_m4 *matrix, double theta)
{
	ft_memset(matrix, '\0', sizeof(t_m4));
	matrix->a[0] = cos(theta);
	matrix->a[2] = sin(theta);
	matrix->b[1] = 1;
	matrix->c[0] = -sin(theta);
	matrix->c[2] = cos(theta);
	matrix->d[3] = true;
	GIMME(matrix);
}

t_m4			*ft_m4rotz(t_m4 *matrix, double theta)
{
	ft_memset(matrix, '\0', sizeof(t_m4));
	matrix->a[0] = cos(theta);
	matrix->a[1] = -sin(theta);
	matrix->b[0] = sin(theta);
	matrix->b[1] = cos(theta);
	matrix->c[2] = 1;
	matrix->d[3] = true;
	GIMME(matrix);
}

t_m4			*ft_m4scale(t_m4 *matrix, double sx, double sy, double sz)
{
	ft_memset(matrix, '\0', sizeof(t_m4));
	matrix->a[0] = sx;
	matrix->b[1] = sy;
	matrix->c[2] = sz;
	matrix->d[3] = true;
	GIMME(matrix);
}

t_m4			*ft_m4trans(t_m4 *matrix, double x, double y, double z)
{
	ft_memset(matrix, '\0', sizeof(t_m4));
	matrix->a[0] = 1;
	matrix->a[3] = x;
	matrix->b[1] = 1;
	matrix->b[3] = y;
	matrix->c[2] = 1;
	matrix->c[3] = z;
	matrix->d[3] = true;
	GIMME(matrix);
}
