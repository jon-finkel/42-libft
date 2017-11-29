/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nfinkel <nfinkel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/24 19:16:08 by nfinkel           #+#    #+#             */
/*   Updated: 2017/10/05 17:52:32 by nfinkel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

static size_t	value_to_trim(const char *s1, const char *s2)
{
	size_t	trim;
	size_t	len;

	trim = 0;
	len = ft_strlen(s1);
	while (*s1 == ' ' || *s1 == '\t' || *s1 == '\n')
	{
		++trim;
		++s1;
	}
	while (*s2 == ' ' || *s2 == '\t' || *s2 == '\n')
	{
		++trim;
		++s2;
	}
	return (trim == len * 2 ? len : trim);
}

char			*ft_strtrim(const char *s)
{
	char	*rev;
	char	*trim;
	int		k;
	size_t	len;

	if (!s)
		return (NULL);
	if (!(rev = ft_strrevcpy(s)))
		return (NULL);
	k = -1;
	len = ft_strlen(s) - value_to_trim(s, rev);
	ft_strclr(rev);
	if (!(trim = ft_strnew(len)))
		return (NULL);
	while (*s == ' ' || *s == '\t' || *s == '\n')
		++s;
	while (len--)
	{
		*(trim + ++k) = *s;
		++s;
	}
	return (trim);
}
