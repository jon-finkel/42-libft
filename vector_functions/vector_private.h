/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector_private.h                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nfinkel <nfinkel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/23 18:59:56 by nfinkel           #+#    #+#             */
/*   Updated: 2018/01/24 16:17:35 by nfinkel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VECTOR_PRIVATE_H
# define VECTOR_PRIVATE_H

# include "../includes/dependencies.h"

# define VEC_MIN_LIMIT 4

typedef struct		s_vector
{
	void			*buff;
	size_t			len;
	size_t			limit;
	size_t			size;
}					t_vector;

extern size_t		ft_vecalloc(t_vector *vector, size_t len);
extern void			*ft_vecend(t_vector *vector);
extern size_t		ft_vecgrow(t_vector *vector, size_t len);
extern void			*ft_vecnpush(t_vector *vector, size_t len);
extern void			*ft_vecpush(t_vector *vector);

#endif
