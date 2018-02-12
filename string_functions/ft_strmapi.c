/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nfinkel <nfinkel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/24 18:32:41 by nfinkel           #+#    #+#             */
/*   Updated: 2018/02/12 20:26:17 by nfinkel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./string.h"

char			*ft_strmapi(const char *s, char (*f)(unsigned int, char))
{
	char		*map;
	int			k;
	size_t		len;

	len = ft_strlen(s);
	map = ft_strnew(len);
	k = -1;
	while ((unsigned int)++k < len)
		*(map + k) = f(k, *(s + k));
	GIMME(map);
}
