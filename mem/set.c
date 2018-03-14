/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nfinkel <nfinkel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/23 22:48:10 by nfinkel           #+#    #+#             */
/*   Updated: 2018/03/13 22:34:32 by nfinkel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "dependencies.h"

void			ft_bzero(void *s, size_t n)
{
	int		k;

	k = -1;
	while ((unsigned int)++k < n)
		((unsigned char *)s)[k] = '\0';
}

void			*ft_memset(void *b, int c, size_t len)
{
	int		k;

	k = -1;
	while ((unsigned int)++k < len)
		*((unsigned char *)b + k) = (unsigned char)c;
	GIMME(b);
}
