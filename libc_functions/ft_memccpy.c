/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nfinkel <nfinkel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/23 22:50:41 by nfinkel           #+#    #+#             */
/*   Updated: 2017/12/01 12:06:53 by nfinkel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

void			*ft_memccpy(void *restrict dst, const void *restrict src, int c,
				size_t n)
{
	char		*d;
	char		*s;
	int			k;

	d = (char *)dst;
	s = (char *)src;
	k = -1;
	while ((unsigned int)++k < n)
	{
		if (*((unsigned char *)s + k) == (unsigned char)c)
		{
			*(d + k) = (unsigned char)c;
			return (dst + k + 1);
		}
		*(d + k) = *(s + k);
	}
	return (NULL);
}
