/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   str_chr.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nfinkel <nfinkel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/21 14:48:31 by nfinkel           #+#    #+#             */
/*   Updated: 2018/02/25 22:33:07 by nfinkel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./str.h"

char			*ft_strchr(const char *s, int c)
{
	while (*s)
	{
		if (*s == (char)c)
			GIMME((char *)s);
		++s;
	}
	GIMME(!(char)c ? (char *)s : NULL);
}

char			*ft_strrchr(const char *s, int c)
{
	char		*last;

	last = NULL;
	while (*s)
	{
		if (*s == (char)c)
			last = (char *)s;
		++s;
	}
	if (!(char)c)
		GIMME((char *)s);
	GIMME(last);
}

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
