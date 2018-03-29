/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mat.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nfinkel <nfinkel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/24 18:39:46 by nfinkel           #+#    #+#             */
/*   Updated: 2018/03/29 19:38:43 by nfinkel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MAT_H
# define MAT_H

# include <math.h>
# include "dependencies.h"

typedef struct		s_vec4
{
	double			x;
	double			y;
	double			z;
	bool			w;
}					t_vec4;

typedef struct		s_m4
{
	double			a[4];
	double			b[4];
	double			c[4];
	bool			d[4];
}					t_m4;

extern size_t		ft_nextpower2(size_t nb);
extern int			ft_pgcd(int a, int b);
extern int32_t		ft_32npow(const intmax_t nb, uint8_t power);
extern int64_t		ft_64npow(const intmax_t nb, uint8_t power);
extern size_t		ft_stnpow(const intmax_t nb, uint8_t power);
extern t_m4			ft_m4rotx(double theta);
extern t_m4			ft_m4roty(double theta);
extern t_m4			ft_m4rotz(double theta);
extern t_m4			ft_m4scale(double sx, double sy, double sz);
extern t_m4			ft_m4trans(double x, double y, double z);
extern t_m4			ft_m4_m4(const t_m4 m1, const t_m4 m2);
extern t_vec4		*ft_v4_m4(t_vec4 *vec, const t_m4 matrix);
extern t_vec4		*ft_vecmap(t_vec4 *vec, double x, double y, double z);
extern t_vec4		*ft_vecnew(double x, double y, double z, bool w);

#endif
