/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nfinkel <nfinkel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/24 10:21:47 by nfinkel           #+#    #+#             */
/*   Updated: 2018/02/12 20:22:35 by nfinkel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/dependencies.h"

int			ft_memcmp(const void *restrict s1, const void *restrict s2,
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
