/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcjoin.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nfinkel <nfinkel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/10 16:30:43 by nfinkel           #+#    #+#             */
/*   Updated: 2018/02/10 16:32:22 by nfinkel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./string.h"

inline char		*ft_strcjoin(char *s1, const char *s2, const char c, bool free)
{
	char		*join;
	size_t		len_s1;
	size_t		len_s2;

	if (!s1 || !s2)
		ZOMG;
	len_s1 = ft_strlen(s1);
	len_s2 = ft_strlen(s2);
	FAILZ(join = ft_strnew(len_s1 + len_s2 + 1), NULL);
	join = ft_strcpy(join, s1);
	join = ft_strncat(join, s2, len_s2);
	join[len_s1 + len_s2] = c;
	if (free == true)
		ft_strdel(&s1);
	GIMME(join);
}
