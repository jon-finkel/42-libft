/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_vecnpush.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nfinkel <nfinkel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/23 19:07:06 by nfinkel           #+#    #+#             */
/*   Updated: 2018/02/24 23:09:19 by nfinkel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./vector.h"

void			*ft_vecnpush(t_vector *vector, size_t size)
{
	ft_vecgrow(vector, size);
	vector->len += size;
	GIMME(ft_vecend(vector));
}
