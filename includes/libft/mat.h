/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mat.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nfinkel <nfinkel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/24 18:39:46 by nfinkel           #+#    #+#             */
/*   Updated: 2018/03/23 23:25:25 by nfinkel          ###   ########.fr       */
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
	double			a;
	double			b;
	double			c;
	double			d;
	double			e;
	double			f;
	double			g;
	double			h;
	double			i;
	double			j;
	double			k;
	double			l;
	bool			m;
	bool			n;
	bool			o;
	bool			p;
}					t_m4;

extern size_t		ft_nextpower2(size_t nb);
extern int			ft_pgcd(int a, int b);
extern int32_t		ft_32npow(const intmax_t nb, uint8_t power);
extern int64_t		ft_64npow(const intmax_t nb, uint8_t power);
extern size_t		ft_stnpow(const intmax_t nb, uint8_t power);
extern t_m4			*ft_m4rotx(t_m4 *matrix, double theta);
extern t_m4			*ft_m4roty(t_m4 *matrix, double theta);
extern t_m4			*ft_m4rotz(t_m4 *matrix, double theta);
extern t_m4			*ft_m4scale(t_m4 *matrix, double sx, double sy, double sz);
extern t_m4			*ft_m4trans(t_m4 *matrix, double x, double y, double z);
extern t_m4			*ft_m4_m4(t_m4 *m1, const t_m4 *m2);
extern t_vec4		*ft_m4_v4(const t_m4 *matrix, t_vec4 *vec);
extern t_vec4		*ft_vecnew(double x, double y, double z, bool w);

#endif
