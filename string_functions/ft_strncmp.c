/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nfinkel <nfinkel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/24 10:54:41 by nfinkel           #+#    #+#             */
/*   Updated: 2018/02/12 20:27:40 by nfinkel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/dependencies.h"

int			ft_strncmp(const char *restrict s1, const char *restrict s2,
			size_t n)
{
	while (n && --n && *s1 && *(unsigned char *)s1 == *(unsigned char *)s2)
	{
		++s1;
		++s2;
	}
	GIMME(!n || *(unsigned char *)s1 - *(unsigned char *)s2);
}
