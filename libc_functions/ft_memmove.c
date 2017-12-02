/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nfinkel <nfinkel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/23 19:24:09 by nfinkel           #+#    #+#             */
/*   Updated: 2017/12/01 12:07:29 by nfinkel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

void			*ft_memmove(void *dst, const void *src, size_t len)
{
	char			*d;
	const char		*s;
	int				k;

	d = (char *)dst;
	s = (char *)src;
	k = -1;
	if (src < dst)
		while ((int)--len >= 0)
			*(d + len) = *(s + len);
	else
		while ((unsigned int)++k < len)
			*(d + k) = *(s + k);
	return (dst);
}
