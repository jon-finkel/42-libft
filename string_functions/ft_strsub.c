/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsub.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nfinkel <nfinkel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/24 18:59:05 by nfinkel           #+#    #+#             */
/*   Updated: 2018/01/17 18:21:09 by nfinkel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

char			*ft_strsub(char *s, unsigned int start, size_t len, bool free)
{
	char		*begin;
	char		*sub;
	int			k;

	if (!s)
		return (NULL);
	begin = s;
	PROTECT(sub = ft_strnew(len), NULL);
	s += start;
	k = -1;
	while ((unsigned int)++k < len)
		*(sub + k) = *(s + k);
	s = begin;
	if (free == true)
		ft_strdel(&s);
	return (sub);
}
