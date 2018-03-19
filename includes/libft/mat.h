/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mat.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nfinkel <nfinkel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/24 18:39:46 by nfinkel           #+#    #+#             */
/*   Updated: 2018/03/19 15:32:08 by nfinkel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MAT_H
# define MAT_H

# include "dependencies.h"

typedef struct		s_vec4
{
	float			x;
	float			y;
	float			z;
	bool			w;
}					t_vec4;

typedef struct		s_matrix4
{
	float			a[4];
	float			b[4];
	float			c[4];
	float			d[4];
}					t_matrix4;

extern size_t			ft_nextpower2(size_t nb);
extern int				ft_pgcd(int a, int b);
extern int32_t			ft_32npow(const intmax_t nb, uint8_t power);
extern int64_t			ft_64npow(const intmax_t nb, uint8_t power);
extern size_t			ft_stnpow(const intmax_t nb, uint8_t power);
extern t_vec4			*ft_vecnew(float x, float y, float z, bool w);

#endif
