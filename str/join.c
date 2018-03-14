/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   join.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nfinkel <nfinkel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/24 19:10:02 by nfinkel           #+#    #+#             */
/*   Updated: 2018/03/14 10:43:18 by nfinkel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/str.h"

char			*ft_strjoin(char *restrict s1, const char *restrict s2,
				bool free)
{
	char		*join;
	size_t		len_s2;

	len_s2 = ft_strlen(s2);
	join = ft_strnew(ft_strlen(s1) + len_s2);
	join = ft_strcpy(join, s1);
	join = ft_strncat(join, s2, len_s2);
	if (free == true)
		ft_strdel((char **)&s1);
	GIMME(join);
}

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
