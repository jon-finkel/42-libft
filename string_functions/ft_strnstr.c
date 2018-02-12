/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nfinkel <nfinkel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/24 11:16:09 by nfinkel           #+#    #+#             */
/*   Updated: 2018/02/12 20:29:00 by nfinkel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./string.h"

char			*ft_strnstr(const char *restrict big,
				const char *restrict little, size_t n)
{
	size_t		len;

	if (!*little)
		GIMME((char *)big);
	len = ft_strlen(little);
	while (n && *big)
	{
		if (len <= n && ft_strncmp(big, little, len) == 0)
			GIMME((char *)big);
		++big;
		--n;
	}
	ZOMG;
}
