/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nfinkel <nfinkel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/18 18:47:15 by nfinkel           #+#    #+#             */
/*   Updated: 2017/12/02 19:59:51 by nfinkel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

/*
** Takes the string 's', split it using 'c' as a separator, and place the
** resulting strings in properly allocated arrays.
*/

static size_t			count_words(const char *s, char c)
{
	size_t		size;

	size = 0;
	if (!s)
		return (0);
	while (*s)
	{
		while (*s == c)
			++s;
		if (*s && *s != c)
			++size;
		while (*s != c && *s)
			++s;
	}
	return (size);
}

static char				*string_shred(const char *s, char c)
{
	char		*dup;
	int			k;
	size_t		size;

	k = -1;
	size = 0;
	while (*s && *s != c)
	{
		++s;
		++size;
	}
	s -= size;
	PROTECT(dup = ft_strnew(size), NULL);
	while (*s && *s != c)
		dup[++k] = *s++;
	return (dup);
}

char					**ft_strsplit(const char *s, char c)
{
	char		**dup;
	int			k;
	size_t		len;

	k = -1;
	len = count_words(s, c) + 1;
	PROTECT(dup = (char **)malloc(sizeof(char *) * len), NULL);
	while (s && *s)
	{
		while (*s == c)
			++s;
		if (*s)
			PROTECT(dup[++k] = string_shred(s, c), NULL);
		while (*s && *s != c)
			++s;
	}
	dup[++k] = NULL;
	return (dup);
}
