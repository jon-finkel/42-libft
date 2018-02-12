/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nfinkel <nfinkel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/21 17:15:37 by nfinkel           #+#    #+#             */
/*   Updated: 2018/02/12 20:27:57 by nfinkel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/dependencies.h"

char			*ft_strncpy(char *restrict dst, const char *restrict src,
				size_t n)
{
	int		k;

	k = -1;
	while ((unsigned int)++k < n)
	{
		if (*src)
		{
			*(dst + k) = *src;
			++src;
		}
		else
			*(dst + k) = '\0';
	}
	GIMME(dst);
}
