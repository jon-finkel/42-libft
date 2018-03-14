/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   chr.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nfinkel <nfinkel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/21 14:48:31 by nfinkel           #+#    #+#             */
/*   Updated: 2018/03/14 10:42:57 by nfinkel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/str.h"

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
