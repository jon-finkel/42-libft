/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   str.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nfinkel <nfinkel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/26 04:31:49 by nfinkel           #+#    #+#             */
/*   Updated: 2019/03/11 21:50:53 by nfinkel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/str.h"

inline char	*ft_strstr(const char *restrict big, const char *restrict little)
{
	int	k;

	if (!*little)
		return ((char *)big);
	while (*big)
	{
		k = -1;
		while (*(unsigned char *)big == *((unsigned char *)little + ++k)
			&& *(little + k))
			++big;
		if (*(little + k) == '\0')
			return ((char *)big - k);
		big -= k - 1;
	}
	return (NULL);
}
