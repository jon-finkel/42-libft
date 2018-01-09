/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nfinkel <nfinkel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/23 23:11:24 by nfinkel           #+#    #+#             */
/*   Updated: 2018/01/09 15:43:04 by nfinkel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

char			*ft_strstr(const char *haystack, const char *needle)
{
	int		k;

	if (!*needle)
		return ((char *)haystack);
	while (*haystack)
	{
		k = -1;
		while (*(unsigned char *)haystack == *((unsigned char *)needle + ++k)
			&& *(needle + k))
			++haystack;
		if (*(needle + k) == '\0')
			return ((char *)haystack - k);
		haystack -= k - 1;
	}
	return (NULL);
}
