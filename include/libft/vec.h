/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vec.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nfinkel <nfinkel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/22 15:30:12 by nfinkel           #+#    #+#             */
/*   Updated: 2018/04/22 16:08:52 by nfinkel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VEC_H
# define VEC_H

# include <math.h>
# include "dependencies.h"

typedef struct	s_p2
{
	int			x;
	int			y;
}				t_p2;

typedef struct	s_v3
{
	double		x;
	double		y;
	double		z;
}				t_v3;

typedef struct	s_v4
{
	double		x;
	double		y;
	double		z;
	bool		w;
}				t_v4;

typedef struct	s_m4
{
	double		a[4];
	double		b[4];
	double		c[4];
	bool		d[4];
}				t_m4;

extern t_p2		*ft_p2ctor(const int x, const int y);
extern t_p2		*ft_p2map(t_p2 *point, const int x, const int y);
extern t_p2		ft_p2new(const int x, const int y);

extern t_v3		**ft_v3center(t_v3 **av, size_t size, const t_p2 pos);
extern t_v3		*ft_v3ctor(const double x, const double y, const double z);
extern t_v3		**ft_v3iter(t_v3 **av, const t_m4 matrix, size_t size);
extern t_v3		*ft_v3map(t_v3 *vec, const double x, const double y,
				const double z);
extern t_v3		ft_v3new(const double x, const double y, const double z);
extern t_v3		*ft_v3_m4(t_v3 *vec, const t_m4 matrix);

extern t_v4		**ft_v4center(t_v4 **av, size_t size, const t_p2 pos);
extern t_v4		*ft_v4ctor(const double x, const double y, const double z,
				const bool w);
extern t_v4		**ft_v4iter(t_v4 **av, const t_m4 matrix, size_t size);
extern t_v4		*ft_v4map(t_v4 *vec, const double x, const double y,
				const double z);
extern t_v4		ft_v4new(const double x, const double y, const double z,
				const bool w);
extern t_v4		*ft_v4_m4(t_v4 *vec, const t_m4 matrix);

extern t_m4		ft_m4rotx(double theta);
extern t_m4		ft_m4roty(double theta);
extern t_m4		ft_m4rotz(double theta);
extern t_m4		ft_m4scale(double sx, double sy, double sz);
extern t_m4		ft_m4trans(double x, double y, double z);

#endif
