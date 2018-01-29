/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_vecfree.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nfinkel <nfinkel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/29 05:09:03 by nfinkel           #+#    #+#             */
/*   Updated: 2018/01/29 05:12:57 by nfinkel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./vector.h"
#include "../memory_functions/memory.h"

inline void			ft_vecfree(t_vector *vector)
{
	int		k;

	k = -1;
	while ((size_t)++k < vector->len)
		ft_memdel(&vector->buff[k]);
}
