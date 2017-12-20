/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nfinkel <nfinkel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/24 18:32:41 by nfinkel           #+#    #+#             */
/*   Updated: 2017/12/02 19:58:09 by nfinkel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

char			*ft_strmapi(const char *s, char (*f)(unsigned int, char))
{
	char		*map;
	int			k;
	size_t		len;

	if (!s || !f)
		return (NULL);
	len = ft_strlen(s);
	PROTECT(map = ft_strnew(len), NULL);
	k = -1;
	while ((unsigned int)++k < len)
		*(map + k) = f(k, *(s + k));
	return (map);
}
