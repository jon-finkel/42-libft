/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsub.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nfinkel <nfinkel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/24 18:59:05 by nfinkel           #+#    #+#             */
/*   Updated: 2017/12/19 22:18:15 by nfinkel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

char			*ft_strsub(char *s, unsigned int start, size_t len,
				enum e_type type)
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
	if (type == FREE)
		free(begin);
	return (sub);
}
