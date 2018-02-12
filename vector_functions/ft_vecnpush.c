/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_vecnpush.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nfinkel <nfinkel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/23 19:07:06 by nfinkel           #+#    #+#             */
/*   Updated: 2018/02/12 20:31:39 by nfinkel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./vector.h"

void			*ft_vecnpush(t_vector *vector, size_t size)
{
	void		*ptr;

	ft_vecgrow(vector, size);
	ptr = ft_vecend(vector);
	vector->len += size;
	GIMME(ptr);
}
