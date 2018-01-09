/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nfinkel <nfinkel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/24 11:16:09 by nfinkel           #+#    #+#             */
/*   Updated: 2018/01/09 15:43:16 by nfinkel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

char			*ft_strnstr(const char *haystack, const char *needle, size_t n)
{
	size_t		len;

	if (!*needle)
		return ((char *)haystack);
	len = ft_strlen(needle);
	while (n && *haystack)
	{
		if (len <= n && ft_strncmp(haystack, needle, len) == 0)
			return ((char *)haystack);
		++haystack;
		--n;
	}
	return (NULL);
}
