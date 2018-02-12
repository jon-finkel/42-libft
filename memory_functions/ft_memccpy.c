/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nfinkel <nfinkel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/23 22:50:41 by nfinkel           #+#    #+#             */
/*   Updated: 2018/02/12 20:22:13 by nfinkel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/dependencies.h"

void			*ft_memccpy(void *restrict dst, const void *restrict src, int c,
				size_t n)
{
	int		k;

	k = -1;
	while ((unsigned int)++k < n)
	{
		if (*((unsigned char *)src + k) == (unsigned char)c)
		{
			*((unsigned char *)dst + k) = (unsigned char)c;
			GIMME(dst + k + 1);
		}
		*((unsigned char *)dst + k) = *((unsigned char *)src + k);
	}
	ZOMG;
}
