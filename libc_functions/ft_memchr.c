/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nfinkel <nfinkel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/24 10:16:33 by nfinkel           #+#    #+#             */
/*   Updated: 2017/12/01 12:07:01 by nfinkel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

void			*ft_memchr(const void *s, int c, size_t n)
{
	int		k;

	k = -1;
	while ((unsigned int)++k < n)
		if (*((unsigned char *)s + k) == (unsigned char)c)
			return ((void *)s + k);
	return (NULL);
}
