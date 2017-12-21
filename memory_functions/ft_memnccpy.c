/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memnccpy.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nfinkel <nfinkel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/20 18:16:02 by nfinkel           #+#    #+#             */
/*   Updated: 2017/12/21 05:40:07 by nfinkel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

void			*ft_memnccpy(void *dst, const void *src, int c, size_t n)
{
	int			k;

	if (!dst || !src)
		return (NULL);
	k = -1;
	while ((unsigned int)++k < n)
	{
		if (*((unsigned char *)src + k) == (unsigned char)c)
		{
			*((unsigned char *)dst + k) = '\0';
			return ((void *)src + k + 1);
		}
		*((unsigned char *)dst + k) = *((unsigned char *)src + k);
	}
	return (NULL);
}
