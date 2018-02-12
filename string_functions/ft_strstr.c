/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nfinkel <nfinkel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/23 23:11:24 by nfinkel           #+#    #+#             */
/*   Updated: 2018/02/12 20:30:26 by nfinkel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/dependencies.h"

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
