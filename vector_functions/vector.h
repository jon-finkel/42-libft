/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nfinkel <nfinkel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/24 18:44:03 by nfinkel           #+#    #+#             */
/*   Updated: 2018/02/12 20:54:58 by nfinkel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VECTOR_H
# define VECTOR_H

# include "../handlers/handlers.h"

# define VEC_MIN_LIMIT 4

typedef struct		s_vector
{
	void			*buff;
	size_t			capacity;
	size_t			len;
	size_t			data_size;
}					t_vector;

extern size_t		ft_vecalloc(t_vector *vector, size_t size);
extern void			*ft_vecbegin(t_vector *vector);
extern void			ft_vecclear(t_vector *vector, t_vdtor del);
extern void			ft_vecdel(t_vector *vector, t_vdtor del);
extern void			*ft_vecend(t_vector *vector);
extern size_t		ft_vecgrow(t_vector *vector, size_t size);
extern void			*ft_vecnpush(t_vector *vector, size_t size);
extern void			*ft_vecpush(t_vector *vector);

#endif
