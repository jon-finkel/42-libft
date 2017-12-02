/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nfinkel <nfinkel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/22 21:05:10 by nfinkel           #+#    #+#             */
/*   Updated: 2017/12/01 12:07:21 by nfinkel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

void			*ft_memcpy(void *restrict dst, const void *restrict src,
				size_t n)
{
	char		*d;
	char		*s;
	int			k;

	d = (char *)dst;
	s = (char *)src;
	k = -1;
	while ((unsigned int)++k < n)
		*(d + k) = *(s + k);
	return (dst);
}
