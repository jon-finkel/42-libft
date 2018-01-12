/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_getenv.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nfinkel <nfinkel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/25 22:58:26 by nfinkel           #+#    #+#             */
/*   Updated: 2018/01/12 21:43:34 by nfinkel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

char				*ft_getenv(const char *name)
{
	char			*buff;
	extern char		**environ;
	int				k;
	size_t			len;

	if (!environ || !name)
		ZOMG;
	buff = NULL;
	len = ft_strlen(name);
	k = -1;
	while (environ[++k])
		if (ft_strnequ((char *)(environ[k]), name, len))
		{
			FAILZ(buff = ft_strnew(ft_strlen(environ[k]) - len - 1), NULL);
			ft_strcpy(buff, ft_strchr(environ[k], '=') + 1);
		}
	return (buff);
}
