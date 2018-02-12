/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcjoin.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nfinkel <nfinkel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/10 16:30:43 by nfinkel           #+#    #+#             */
/*   Updated: 2018/02/12 20:24:13 by nfinkel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./string.h"

char			*ft_strcjoin(char *restrict s1, const char *restrict s2,
				const char c, bool free)
{
	char		*join;
	size_t		len_s1;
	size_t		len_s2;

	len_s1 = ft_strlen(s1);
	len_s2 = ft_strlen(s2);
	join = ft_strnew(len_s1 + len_s2 + 1);
	join = ft_strcpy(join, s1);
	join = ft_strncat(join, s2, len_s2);
	join[len_s1 + len_s2] = c;
	if (free == true)
		ft_strdel((char **)&s1);
	GIMME(join);
}
