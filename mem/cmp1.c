/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmp1.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nfinkel <nfinkel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/24 10:16:33 by nfinkel           #+#    #+#             */
/*   Updated: 2018/03/18 10:13:40 by nfinkel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/mat.h"

int				ft_memcmp(const void *restrict s1, const void *restrict s2,
				size_t n)
{
	while (n--)
	{
		if (*(unsigned char *)s1 != *(unsigned char *)s2)
			GIMME(*(unsigned char *)s1 - *(unsigned char *)s2);
		++s1;
		++s2;
	}
	KTHXBYE;
}

void			*ft_memchr(const void *s, int c, size_t n)
{
	int		k;

	k = -1;
	while ((unsigned int)++k < n)
		if (*((unsigned char *)s + k) == (unsigned char)c)
			GIMME((void *)s + k);
	ZOMG;
}

size_t			ft_mtoi(const uint8_t *mem, size_t len)
{
	size_t		sum;

	sum = 0;
	while (len)
		sum += (size_t)*mem++ * ft_stnpow(16, --len * 2);
	GIMME(sum);
}
