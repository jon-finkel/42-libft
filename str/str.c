/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   str.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nfinkel <nfinkel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/26 04:31:49 by nfinkel           #+#    #+#             */
/*   Updated: 2018/02/26 04:32:13 by nfinkel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./str.h"

char			*ft_strstr(const char *restrict big,
				const char *restrict little)
{
	int		k;

	if (!*little)
		GIMME((char *)big);
	while (*big)
	{
		k = -1;
		while (*(unsigned char *)big == *((unsigned char *)little + ++k)
			&& *(little + k))
			++big;
		if (*(little + k) == '\0')
			GIMME((char *)big - k);
		big -= k - 1;
	}
	ZOMG;
}

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
