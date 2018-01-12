/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nfinkel <nfinkel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/24 19:10:02 by nfinkel           #+#    #+#             */
/*   Updated: 2018/01/12 21:48:17 by nfinkel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

char			*ft_strjoin(char *s1, const char *s2, t_type type)
{
	char		*join;
	size_t		len_s2;

	if (!s1 || !s2)
		ZOMG;
	len_s2 = ft_strlen(s2);
	FAILZ(join = ft_strnew(ft_strlen(s1) + len_s2), NULL);
	join = ft_strcpy(join, s1);
	join = ft_strncat(join, s2, len_s2);
	if (type == E_FREE)
		ft_strdel(&s1);
	return (join);
}
