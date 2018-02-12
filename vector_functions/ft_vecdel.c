/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_vecdel.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nfinkel <nfinkel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/29 06:27:15 by nfinkel           #+#    #+#             */
/*   Updated: 2018/02/12 20:55:13 by nfinkel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./vector.h"

void			ft_vecdel(t_vector *vector, t_vdtor del)
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
