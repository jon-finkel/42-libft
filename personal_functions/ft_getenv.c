/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_getenv.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nfinkel <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/13 18:24:25 by nfinkel           #+#    #+#             */
/*   Updated: 2017/12/14 17:24:41 by nfinkel          ###   ########.fr       */
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
		return (NULL);
	len = ft_strlen(name);
	k = -1;
	while (environ[++k])
		if (ft_strnequ((char *)(environ[k]), name, len))
		{
			PROTECT(buff = ft_strnew(ft_strlen(environ[k]) - len - 1), NULL);
			ft_strcpy(buff, ft_strchr(environ[k], '=') + 1);
		}
	return (buff);
}