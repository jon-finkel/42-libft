/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_vecfree.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nfinkel <nfinkel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/29 05:09:03 by nfinkel           #+#    #+#             */
/*   Updated: 2018/01/29 05:57:51 by nfinkel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./vector.h"

inline void			ft_vecfree(t_vector *vector, void (*del)(void *))
{
	char		*ptr;

	if (vector->buff && del)
	{
		ptr = (char *)ft_vecbegin(vector) - vector->data_size;
		while ((ptr += vector->data_size) != (char *)ft_vecend(vector))
			del(ptr);
		vector->len = 0;
	}
}
