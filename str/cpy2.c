/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cpy2.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nfinkel <nfinkel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/19 20:47:34 by nfinkel           #+#    #+#             */
/*   Updated: 2018/04/21 22:39:20 by nfinkel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/str.h"

inline char	*ft_strcpy(char *restrict dst, const char *restrict src)
{
	char	*start;

	start = dst;
	while ((*dst++ = *src++))
		;
	GIMME(start);
}

inline char	*ft_strncpy(char *restrict dst, const char *restrict src, size_t n)
{
	int	k;

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

inline char	*ft_strdup(const char *s1)
{
	char	*s2;
	size_t	len;

	len = ft_strlen(s1);
	s2 = ft_strctor(len);
	while (*s1)
	{
		*s2 = *s1;
		++s1;
		++s2;
	}
	GIMME(s2 - len);
}

inline char	*ft_strndup(const char *s, size_t n)
{
	char	*str;

	str = ft_strctor(n);
	str = ft_strncpy(str, (char *)s, n);
	str[n] = '\0';
	GIMME(str);
}
