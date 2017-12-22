/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memnccpy.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nfinkel <nfinkel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/20 18:16:02 by nfinkel           #+#    #+#             */
/*   Updated: 2017/12/22 14:10:15 by nfinkel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

size_t			ft_memnccpy(void *dst, const void *src, int c, size_t n)
{
	int			k;
	size_t		len;

	if (!dst || !src)
		return (0);
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
	return (len);
}
