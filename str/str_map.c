/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map2.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nfinkel <nfinkel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/24 17:31:07 by nfinkel           #+#    #+#             */
/*   Updated: 2019/03/11 21:49:51 by nfinkel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/str.h"

inline char	*ft_strmap(const char *s, char (*f)(char))
{
	char		*map;
	int			k;
	size_t		len;

	k = -1;
	len = ft_strlen(s);
	map = ft_strctor(len);
	while ((unsigned int)++k < len)
		*(map + k) = f(*(s + k));
	return (map);
}
