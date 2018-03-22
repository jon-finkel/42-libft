/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mat.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nfinkel <nfinkel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/24 18:39:46 by nfinkel           #+#    #+#             */
/*   Updated: 2018/03/22 16:27:21 by nfinkel          ###   ########.fr       */
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

typedef struct		s_matrix4
{
	double			a[4];
	double			b[4];
	double			c[4];
	double			d[4];
}					t_matrix4;

extern size_t			ft_nextpower2(size_t nb);
extern int				ft_pgcd(int a, int b);
extern int32_t			ft_32npow(const intmax_t nb, uint8_t power);
extern int64_t			ft_64npow(const intmax_t nb, uint8_t power);
extern size_t			ft_stnpow(const intmax_t nb, uint8_t power);
extern t_vec4			*ft_vecnew(double x, double y, double z, bool w);
extern t_vec4			*ft_vecrotx(t_vec4 *vec, double theta);
extern t_vec4			*ft_vecroty(t_vec4 *vec, double theta);
extern t_vec4			*ft_vecrotz(t_vec4 *vec, double theta);

#endif
