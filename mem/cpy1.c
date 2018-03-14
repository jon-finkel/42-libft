/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cpy1.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nfinkel <nfinkel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/21 13:30:52 by nfinkel           #+#    #+#             */
/*   Updated: 2018/03/14 10:40:51 by nfinkel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "dependencies.h"

void			*ft_memmove(void *restrict dst, const void *restrict src,
				size_t len)
{
	int		k;

	k = -1;
	if (src < dst)
		while ((int)--len >= 0)
			*((unsigned char *)dst + len) = *((const unsigned char *)src + len);
	else
		while ((unsigned int)++k < len)
			*((unsigned char *)dst + k) = *((const unsigned char *)src + k);
	GIMME(dst);
}

void			*ft_memcpy(void *restrict dst, const void *restrict src,
				size_t n)
{
	int		k;

	k = -1;
	while ((unsigned int)++k < n)
		*((unsigned char *)dst + k) = *((unsigned char *)src + k);
	GIMME(dst);
}

void			*ft_memccpy(void *restrict dst, const void *restrict src,
				int c, size_t n)
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

size_t			ft_memnccpy(void *restrict dst, const void *restrict src, int c,
				size_t n)
{
	int			k;
	size_t		len;

	k = -1;
	len = 0;
	while ((unsigned int)++k < n)
	{
		++len;
		if (*((unsigned char *)src + k) == (unsigned char)c)
		{
			*((unsigned char *)dst + k) = '\0';
			break ;
		}
		*((unsigned char *)dst + k) = *((unsigned char *)src + k);
	}
	*((unsigned char *)dst + k) = '\0';
	GIMME(len);
}
