/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nfinkel <nfinkel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/24 17:31:07 by nfinkel           #+#    #+#             */
/*   Updated: 2017/12/02 19:57:55 by nfinkel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

char			*ft_strmap(const char *s, char (*f)(char))
{
	char		*map;
	int			k;
	size_t		len;

	if (!s || !f)
		return (NULL);
	k = -1;
	len = ft_strlen(s);
	PROTECT(map = ft_strnew(len), NULL);
	while ((unsigned int)++k < len)
		*(map + k) = f(*(s + k));
	return (map);
}
