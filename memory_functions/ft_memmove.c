/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nfinkel <nfinkel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/23 19:24:09 by nfinkel           #+#    #+#             */
/*   Updated: 2018/02/12 20:22:54 by nfinkel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/dependencies.h"

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
