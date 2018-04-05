/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mat.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nfinkel <nfinkel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/24 18:39:46 by nfinkel           #+#    #+#             */
/*   Updated: 2018/04/05 13:56:12 by nfinkel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MAT_H
# define MAT_H

# include <math.h>
# include "dependencies.h"

typedef struct		s_p2
{
	int				x;
	int				y;
}					t_p2;

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
extern t_p2			ft_p2ctor(const int x, const int y);
extern t_vec4		*ft_v4_m4(t_vec4 *vec, const t_m4 matrix);
extern void			ft_veccenter(t_vec4 **avec, size_t size, const t_vec4 pos);
extern void			ft_veciter(t_vec4 **avec, const t_m4 matrix, size_t size);
extern t_vec4		*ft_vecmap(t_vec4 *vec, double x, double y, double z);
extern t_vec4		*ft_vecnew(double x, double y, double z, bool w);

#endif
